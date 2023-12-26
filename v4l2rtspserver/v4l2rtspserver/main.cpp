/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** main.cpp
** 
** V4L2 RTSP streamer                                                                 
**                                                                                    
** H264 capture using V4L2                                                            
** RTSP using live555                                                                 
**                                                                                    
** -------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <dirent.h>

#include <sstream>

// libv4l2
#include <linux/videodev2.h>

// project
#include "logger.h"

#include "V4l2Device.h"
#include "V4l2Output.h"

#include "DeviceSourceFactory.h"
#include "V4l2RTSPServer.h"


// -----------------------------------------
//    signal handler
// -----------------------------------------
char quit = 0;
void sighandler(int n)
{ 
	printf("SIGINT\n");
	quit =1;
}

// -------------------------------------------------------
//    decode multicast url <group>:<rtp_port>:<rtcp_port>
// -------------------------------------------------------
void decodeMulticastUrl(const std::string & maddr, in_addr & destinationAddress, unsigned short & rtpPortNum, unsigned short & rtcpPortNum)
{
	std::istringstream is(maddr);
	std::string ip;
	getline(is, ip, ':');		

    // maddr没有指定,IP肯定是为空的
	if (!ip.empty())
	{
		destinationAddress.s_addr = inet_addr(ip.c_str());
	}						
	
	std::string port;
	getline(is, port, ':');						
	rtpPortNum = 20000;

    // maddr没有指定,port肯定是为空的
	if (!port.empty())
	{
		rtpPortNum = atoi(port.c_str());
	}	
	rtcpPortNum = rtpPortNum+1;
}

// -------------------------------------------------------
//    split video,audio device
// -------------------------------------------------------
void decodeDevice(const std::string & device, std::string & videoDev, std::string & audioDev)
{
	std::istringstream is(device);
	getline(is, videoDev, ',');						
	getline(is, audioDev);						
}

std::string getDeviceName(const std::string & devicePath)
{
	std::string deviceName(devicePath);
	size_t pos = deviceName.find_last_of('/');
	if (pos != std::string::npos) {
		deviceName.erase(0,pos+1);
	}
	return deviceName;
}


// 本次阅读,以 v4l2rtspserver /dev/video0 执行
// -----------------------------------------
//    entry point
// -----------------------------------------
int main(int argc, char** argv) 
{
	// default parameters
	const char *dev_name = "/dev/video0,/dev/video0";	
	unsigned int format = ~0;
	std::list<unsigned int> videoformatList;
	int width = 0;
	int height = 0;
	int queueSize = 5;
	int fps = 25;
	unsigned short rtspPort = 8554;
	unsigned short rtspOverHTTPPort = 0;
	bool multicast = false;
	int verbose = 0;
	std::string outputFile;
	V4l2IoType ioTypeIn  = IOTYPE_MMAP;
	V4l2IoType ioTypeOut = IOTYPE_MMAP;
	int openflags = O_RDWR | O_NONBLOCK; 
	std::string url = "unicast";
	std::string murl = "multicast";
	std::string tsurl = "ts";
	V4L2DeviceSource::CaptureMode captureMode = V4L2DeviceSource::CAPTURE_INTERNAL_THREAD;
	std::string maddr;
	bool repeatConfig = true;
	int timeout = 65;
	int defaultHlsSegment = 2;
	unsigned int hlsSegment = 0;
	const char* sslKeyCert = NULL;
	const char* realm = NULL;
	std::list<std::string> userPasswordList;
	std::string webroot;
#ifdef HAVE_ALSA	
	int audioFreq = 44100;
	int audioNbChannels = 2;
	std::list<snd_pcm_format_t> audioFmtList;
	snd_pcm_format_t audioFmt = SND_PCM_FORMAT_UNKNOWN;
#endif	
	const char* defaultPort = getenv("PORT");
	if (defaultPort != NULL) {
		rtspPort = atoi(defaultPort);
	}

	// decode parameters
	int c = 0;     
	while ((c = getopt (argc, argv, "v::Q:O:b:" "I:P:p:m::u:M::ct:S::x:" "R:U:" "rwBsf::F:W:H:G:" "A:C:a:" "Vh")) != -1)
	{
		switch (c)
		{
			case 'v':	verbose    = 1; if (optarg && *optarg=='v') verbose++;  break;
			case 'Q':	queueSize  = atoi(optarg); break;
			case 'O':	outputFile = optarg; break;
			case 'b':	webroot = optarg; break;
			
			// RTSP/RTP
			case 'I':       ReceivingInterfaceAddr  = inet_addr(optarg); break;
			case 'P':	rtspPort                = atoi(optarg); break;
			case 'p':	rtspOverHTTPPort        = atoi(optarg); break;
			case 'u':	url                     = optarg; break;
			case 'm':	multicast = true; murl  = optarg ? optarg : murl; break;
			case 'M':	multicast = true; maddr = optarg ? optarg : maddr; break;
			case 'c':	repeatConfig            = false; break;
			case 't':	timeout                 = atoi(optarg); break;
			case 'S':	hlsSegment              = optarg ? atoi(optarg) : defaultHlsSegment; break;
			case 'x':	sslKeyCert              = optarg; break;

			// users
			case 'R':       realm                   = optarg; break;
			case 'U':       userPasswordList.push_back(optarg); break;
			
			// V4L2
			case 'r':	ioTypeIn  = IOTYPE_READWRITE; break;
			case 'w':	ioTypeOut = IOTYPE_READWRITE; break;	
			case 'B':	openflags = O_RDWR; break;	
			case 's':	captureMode = V4L2DeviceSource::CAPTURE_LIVE555_THREAD; break;
			case 'f':	format    = V4l2Device::fourcc(optarg); if (format) {videoformatList.push_back(format);};  break;
			case 'F':	fps       = atoi(optarg); break;
			case 'W':	width     = atoi(optarg); break;
			case 'H':	height    = atoi(optarg); break;
			case 'G':   sscanf(optarg,"%dx%dx%d", &width, &height, &fps); break;
			
			// ALSA
#ifdef HAVE_ALSA	
			case 'A':	audioFreq = atoi(optarg); break;
			case 'C':	audioNbChannels = atoi(optarg); break;
			case 'a':	audioFmt = V4l2RTSPServer::decodeAudioFormat(optarg); if (audioFmt != SND_PCM_FORMAT_UNKNOWN) {audioFmtList.push_back(audioFmt);} ; break;
#endif			
			
			// version
			case 'V':	
				std::cout << VERSION << std::endl;
				exit(0);			
			break;
			
			// help
			case 'h':
			default:
			{
				std::cout << argv[0] << " [-v[v]] [-Q queueSize] [-O file]"                                        << std::endl;
				std::cout << "\t          [-I interface] [-P RTSP port] [-p RTSP/HTTP port] [-m multicast url] [-u unicast url] [-M multicast addr] [-c] [-t timeout] [-T] [-S[duration]]" << std::endl;
				std::cout << "\t          [-r] [-w] [-s] [-f[format] [-W width] [-H height] [-F fps] [device] [device]"                        << std::endl;
				std::cout << "\t -v               : verbose"                                                                                          << std::endl;
				std::cout << "\t -vv              : very verbose"                                                                                     << std::endl;
				std::cout << "\t -Q <length>      : Number of frame queue  (default "<< queueSize << ")"                                              << std::endl;
				std::cout << "\t -O <output>      : Copy captured frame to a file or a V4L2 device"                                                   << std::endl;
				std::cout << "\t -b <webroot>     : path to webroot" << std::endl;
				
				std::cout << "\t RTSP/RTP options"                                                                                           << std::endl;
				std::cout << "\t -I <addr>        : RTSP interface (default autodetect)"                                                              << std::endl;
				std::cout << "\t -P <port>        : RTSP port (default "<< rtspPort << ")"                                                            << std::endl;
				std::cout << "\t -p <port>        : RTSP over HTTP port (default "<< rtspOverHTTPPort << ")"                                          << std::endl;
				std::cout << "\t -U <user>:<pass> : RTSP user and password"                                                                    << std::endl;
				std::cout << "\t -R <realm>       : use md5 password 'md5(<username>:<realm>:<password>')"                                            << std::endl;
				std::cout << "\t -u <url>         : unicast url (default " << url << ")"                                                              << std::endl;
				std::cout << "\t -m <url>         : multicast url (default " << murl << ")"                                                           << std::endl;
				std::cout << "\t -M <addr>        : multicast group:port (default is random_address:20000)"                                           << std::endl;
				std::cout << "\t -c               : don't repeat config (default repeat config before IDR frame)"                                     << std::endl;
				std::cout << "\t -t <timeout>     : RTCP expiration timeout in seconds (default " << timeout << ")"                                   << std::endl;
				std::cout << "\t -S[<duration>]   : enable HLS & MPEG-DASH with segment duration  in seconds (default " << defaultHlsSegment << ")" << std::endl;
				std::cout << "\t -x <sslkeycert>  : enable RTSPS & SRTP"                                 << std::endl;
				
				std::cout << "\t V4L2 options"                                                                                               << std::endl;
				std::cout << "\t -r               : V4L2 capture using read interface (default use memory mapped buffers)"                            << std::endl;
				std::cout << "\t -w               : V4L2 capture using write interface (default use memory mapped buffers)"                           << std::endl;
				std::cout << "\t -B               : V4L2 capture using blocking mode (default use non-blocking mode)"                                 << std::endl;
				std::cout << "\t -s               : V4L2 capture using live555 mainloop (default use a reader thread)"                                << std::endl;
				std::cout << "\t -f               : V4L2 capture using current capture format (-W,-H,-F are ignored)"                                 << std::endl;
				std::cout << "\t -f<format>       : V4L2 capture using format (-W,-H,-F are used)"                                                    << std::endl;
				std::cout << "\t -W <width>       : V4L2 capture width (default "<< width << ")"                                                      << std::endl;
				std::cout << "\t -H <height>      : V4L2 capture height (default "<< height << ")"                                                    << std::endl;
				std::cout << "\t -F <fps>         : V4L2 capture framerate (default "<< fps << ")"                                                    << std::endl;
				std::cout << "\t -G <w>x<h>[x<f>] : V4L2 capture format (default "<< width << "x" << height << "x" << fps << ")"  << std::endl;
				
#ifdef HAVE_ALSA	
				std::cout << "\t ALSA options"                                                                                               << std::endl;
				std::cout << "\t -A freq          : ALSA capture frequency and channel (default " << audioFreq << ")"                                << std::endl;
				std::cout << "\t -C channels      : ALSA capture channels (default " << audioNbChannels << ")"                                       << std::endl;
				std::cout << "\t -a fmt           : ALSA capture audio format (default S16_BE)"                                                      << std::endl;
#endif
				
				std::cout << "\t Devices :"                                                                                                    << std::endl;
				std::cout << "\t [V4L2 device][,ALSA device] : V4L2 capture device or/and ALSA capture device (default "<< dev_name << ")"     << std::endl;
				exit(0);
			}
		}
	}

    // 这里把设备节点加入 devList, /dev/video0
	std::list<std::string> devList;
	while (optind<argc)
	{
		devList.push_back(argv[optind]);
		optind++;
	}
	if (devList.empty())
	{
		devList.push_back(dev_name);
	}
	
    // 指定视频格式列表, h264, mjpeg, jpeg, nv12
	// default format tries
	if ((videoformatList.empty()) && (format!=0)) {
		videoformatList.push_back(V4L2_PIX_FMT_H264);
		videoformatList.push_back(V4L2_PIX_FMT_MJPEG);
		videoformatList.push_back(V4L2_PIX_FMT_JPEG);
		videoformatList.push_back(V4L2_PIX_FMT_NV12);
	}

#ifdef HAVE_ALSA	
	// default audio format tries
	if (audioFmtList.empty()) {
		audioFmtList.push_back(SND_PCM_FORMAT_S16_LE);
		audioFmtList.push_back(SND_PCM_FORMAT_S16_BE);
	}
#endif	
	
	// init logger
	initLogger(verbose);
	LOG(NOTICE) << "Version: " << VERSION << " live555 version:" << LIVEMEDIA_LIBRARY_VERSION_STRING;
     	
	// 创建rtsp服务,这里使用到了live555的模块,
	// create RTSP server
	V4l2RTSPServer rtspServer(rtspPort, rtspOverHTTPPort, timeout, hlsSegment, userPasswordList, realm, webroot, sslKeyCert);
	if (!rtspServer.available()) 
	{
		LOG(ERROR) << "Failed to create RTSP server: " << rtspServer.getResultMsg();
	}
	else
	{		
		// decode multicast info
		struct in_addr destinationAddress;
        // 随机获取一个IP地址???
		destinationAddress.s_addr = chooseRandomIPv4SSMAddress(*rtspServer.env());

        // 指定rtp和rtcp的端口,相邻的一个奇一个偶
		unsigned short rtpPortNum = 20000;
		unsigned short rtcpPortNum = rtpPortNum+1;
        // maddr 这次执行没有指定内容
        // 这里是解析maddr,构建 destinationAddress,rtpPortNum 和 rtpPortNum
        // maddr 没有内容,不会修改以上变量
		decodeMulticastUrl(maddr, destinationAddress, rtpPortNum, rtpPortNum);	

		std::list<V4l2Output*> outList;
		int nbSource = 0;


        // 遍历 devList, 这次执行 devList 里面只有 /dev/video0
        // 循环将会执行一次
		std::list<std::string>::iterator devIt;
		for ( devIt=devList.begin() ; devIt!=devList.end() ; ++devIt)
		{
            // deviceName 是 /dev/video0
			std::string deviceName(*devIt);
			
			std::string videoDev;
			std::string audioDev;
            // 分割字符串 deviceName ,按','分割,第一个字符串给 videoDev, 第二个给 audioDev
            // 这里结果 videoDev 将为 /dev/video0,  audioDev 为空
            decodeDevice(deviceName, videoDev, audioDev);

            std::string baseUrl;

            // 这次执行没有指定 outputFile, 结果 output 为空
			std::string output(outputFile);

            // devList.size = 1
			if (devList.size() > 1)
			{
				baseUrl = getDeviceName(videoDev);
				baseUrl.append("_");
				// output is not compatible with multiple device
				output.assign("");
			}


			V4l2Output* out = NULL;
            // 设置摄像头的参数,
            // videoDev /dev/video0
            // width 0, height0, fps 25,
            // ioTypeIn IOTYPE_MMAP
            // verbose 0
            // openflags O_RDWR | O_NONBLOCK
			V4L2DeviceParameters inParam(videoDev.c_str(), videoformatList, width, height, fps, ioTypeIn, verbose, openflags);

            // 创建一个 视频 采集器???
            // 这个采集器,会启动线程,读取摄像头数据
            // 如果指定了文件,会将数据写入文件
            // 然后将一帧一帧的数据放入队列中
			StreamReplicator* videoReplicator = rtspServer.CreateVideoReplicator( 
					inParam,
					queueSize, captureMode, repeatConfig,
					output, ioTypeOut, out);
			if (out != NULL) {
                // 把 V4l2Output 放入列表管理,如果有
                // V4l2Output 是传入文件的实例化对象
				outList.push_back(out);
			}
					
			// Init Audio Capture
			StreamReplicator* audioReplicator = NULL;

            // 如果开启alsa,还需要创建一个,音频的采集器,,这个稍后分析
#ifdef HAVE_ALSA
			audioReplicator = rtspServer.CreateAudioReplicator(
					audioDev, audioFmtList, audioFreq, audioNbChannels, verbose,
					queueSize, captureMode);		
#endif
					
            // 创建3个session,我们一个一个分析
            // 在分析之前,我们再次回顾下前面的内容,,
            // 1 打开了摄像头
            // 2 开启了线程
            // 3 循环读取摄像头数据按队列保存的一个队列中

            // ServerMediaSession 是live555的模块的类
            // 多播
			// Create Multicast Session
			if (multicast)						
			{		
                // baseUrl 因为只有一个设备/dev/video0,所以 baseUrl 是空的, multicast 是 "multicast", 最终是 "multicast"
                // destinationAddress 是一个ip地址
                // rtpPortNum rtcpPortNum 是端口
                // videoReplicator audioReplicator 分别是视频和音频的采集器
				ServerMediaSession* sms = rtspServer.AddMulticastSession(baseUrl+murl, destinationAddress, rtpPortNum, rtcpPortNum, videoReplicator, audioReplicator);
				if (sms) {
					nbSource += sms->numSubsessions();
				}
			}
			
			// Create HLS Session					
			if (hlsSegment > 0)
			{
				ServerMediaSession* sms = rtspServer.AddHlsSession(baseUrl+tsurl, hlsSegment, videoReplicator, audioReplicator);
				if (sms) {
					nbSource += sms->numSubsessions();
				}
			}
			
            // 单播
			// Create Unicast Session
			ServerMediaSession* sms  = rtspServer.AddUnicastSession(baseUrl+url, videoReplicator, audioReplicator);		
			if (sms) {
				nbSource += sms->numSubsessions();
			}
		}

		if (nbSource>0)
		{
			// main loop
			signal(SIGINT,sighandler);
            // 开始循环处理事件???,,,在哪里创建并初始化的呢
			rtspServer.eventLoop(&quit); 
			LOG(NOTICE) << "Exiting....";			
		}

		while (!outList.empty())
		{
			V4l2Output* out = outList.back();
			delete out;
			outList.pop_back();
		}
	}
	
	return 0;
}



