#include <cstdlib>
#include <stdio.h>
#include "sgx_capable.h"

int main(int argc, char* argv[])
{
    sgx_device_status_t *supported = (sgx_device_status_t*)malloc(sizeof(sgx_device_status_t));

    if (sgx_cap_get_status(supported)) {
	printf("Failed to determine SGX compatability\n");
	return 1;
    }
    
    printf("Compatability will be a combination of the following bits:\n" 
	   "#define ST_SGX_UNSUPPORTED 0x0\n"
	   "#define ST_SGX_CAPABLE 0x1\n" 
	   "#define ST_SGX_ENABLED 0x2\n" 
	   "#define ST_SGX_REBOOT_REQUIRED 0x4\n"
           "#define ST_SGX_BIOS_ENABLE_REQUIRED 0x8\n\n"
           "Compatability result is:%d\n",*supported);
    return 0;
}
