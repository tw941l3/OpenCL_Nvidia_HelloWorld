#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
//#include <oclUtils.h>
//#include <shrQATest.h>
int main()
{
	char dname[500];
	cl_device_id devices[10];
	cl_platform_id platform_id = NULL;
	cl_uint num_devices, entries;
	cl_ulong long_entries;
	int d;
	cl_int err;
	size_t p_size;

	/*��o��e���x*/
	err = clGetPlatformIDs(1, &platform_id, NULL);
	/*��o��e���x��T*/
	clGetPlatformInfo(platform_id, CL_PLATFORM_NAME, 500, dname, NULL);
	printf("CL_PLATFORM_NAME = %s\n", dname);
	clGetPlatformInfo(platform_id, CL_PLATFORM_VERSION, 500, dname, NULL);
	printf("CL_PLATFORM_VERSION = %s\n", dname);
	/*��o�ثe���x�W�Ҧ��i�ϥ�OpenCL���]��*/
	clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ALL, 10, devices, &num_devices);
	printf("%d devices found\n", num_devices);
	/*�d�ߨC��OpenCL�]�ƪ���T*/
	for (d = 0; d < num_devices; ++d)
	{
		clGetDeviceInfo(devices[d], CL_DEVICE_NAME, 500, dname, NULL);
		printf("Device #%d name = %s\n", d, dname);

		clGetDeviceInfo(devices[d], CL_DRIVER_VERSION, 500, dname, NULL);
		printf("\tDriver version = %s\n", dname);

		clGetDeviceInfo(devices[d], CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(cl_ulong), &long_entries, NULL);
		printf("\tGlobal Memory Cache (MB) :\t%llu\n", long_entries / 1024 / 1024);

		clGetDeviceInfo(devices[d], CL_DEVICE_LOCAL_MEM_SIZE, sizeof(cl_ulong), &long_entries, NULL);
		printf("\tLocal Memory Cache (KB) :\t%llu\n", long_entries / 1024);

		clGetDeviceInfo(devices[d], CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(cl_ulong), &long_entries, NULL);
		printf("\tMax clock (MHz) :\t%llu\n", long_entries);

		clGetDeviceInfo(devices[d], CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(size_t), &p_size, NULL);
		printf("\tMax Work Group Size:\t%d\n", p_size);

		clGetDeviceInfo(devices[d], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_uint), &entries, NULL);
		printf("\tNumber of parallel compute cores:\t%d\n", entries);
	}
	printf("Hello world\n");
	system("pause");
}