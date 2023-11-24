#include <stdio.h>

#include <limits.h>
#include <float.h>

int main()
{
	printf("unsigned char(header) : %d ~ %u\n", 0,UCHAR_MAX);
	printf("unsigned char(calc)   : %d ~ %u\n", 0, (1<<8) - 1);
	printf("signed char(header)   : %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("signed char(calc)     : %d ~ %d\n", (signed char)(1<<8 - 1), (signed char)((1<<8 - 1) - 1));

	printf("unsigned short(header): %d ~ %u\n", 0, USHRT_MAX);
	printf("unsigned short(calc)  : %d ~ %u\n", 0, (1<<16) - 1);
	printf("signed short(header)  : %d ~ %d\n", SHRT_MIN, SHRT_MAX);
	printf("signed short(calk)    : %d ~ %d\n", (signed short)(1<<16 - 1), (signed short)((1<<16 - 1) - 1));

	printf("unsigned int(header)  : %d ~ %u\n", 0, (unsigned int)UINT_MAX);
	printf("unsigned int(calc)    : %d ~ %u\n", 0, (unsigned int)((1l<<32) - 1));
	printf("signed int(header)    : %d ~ %d\n", INT_MIN, INT_MAX);
	printf("signed int(calc)      : %d ~ %d\n", (signed int)(1<<32 - 1), (signed int)((1<<32 - 1) - 1));

	printf("unsigned long(header) : %d ~ %lu\n", 0, ULONG_MAX);
	printf("unsigned long(calc)   : %d ~ %lu\n", 0, (1l<<64) - 1l);
	printf("signed long(header)   : %ld ~ %ld\n", LONG_MIN, LONG_MAX);
	printf("signed long(calc)     : %ld ~ %ld\n", (signed long)(1l<<64 - 1l), (signed long)((1l<<64 - 1l) - 1l));

	printf("float(header)         : %e ~ %e\n", FLT_MIN, FLT_MAX);
	printf("double(header)        : %e ~ %e\n", DBL_MIN, DBL_MAX);
	printf("long double(header)   : %le ~ %le\n", (long double)LDBL_MIN, (long double)LDBL_MAX);
}
