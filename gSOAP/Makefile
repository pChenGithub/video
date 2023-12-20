target += testMobileCode

dir_mobile += MobileCode
src_mobile += $(wildcard ${dir_mobile}/*.c)
CFLAGS += -IMobileCode
#LDFLAGS += -lgsoap

all: ${target}

${target}: ${src_mobile}

