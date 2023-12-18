#include <stdio.h>
#include "MobileCodeWSSoap.nsmap"
#include "soapH.h"

int main(int argc, char const *argv[])
{
    const char  *endpoint = "http://ws.webxml.com.cn/WebServices/MobileCodeWS.asmx";

    struct soap *soap = NULL;
    struct _ns1__getMobileCodeInfo          req;
    struct _ns1__getMobileCodeInfoResponse  resp;

    soap = soap_new(); 
    soap_set_mode(soap, SOAP_C_UTFSTRING);

    memset(&req, 0x00, sizeof(req));
    req.mobileCode = argv[1];
    req.userID     = NULL;

    if(SOAP_OK == soap_call___ns1__getMobileCodeInfo(soap, endpoint, NULL, &req, &resp)) {
        if (NULL != resp.getMobileCodeInfoResult) {
            printf("%s\n", resp.getMobileCodeInfoResult);
        }
    }

    soap_destroy(soap);                                                         // delete deserialized objects
    soap_end(soap);

    soap_free(soap);
    return 0;
}


