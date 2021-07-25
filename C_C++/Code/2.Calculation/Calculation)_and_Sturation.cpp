#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define FALSE 0
#define TRUE  1

#if 0
#define INT32_MIN (-2147483648)
#define INT32_MAX ( 2147483647)
#else
#define INT8_MIN 0x80
#define INT8_MAX 0x7F

#define UINT8_MIN 0x00
#define UINT8_MAX 0xFF

#define INT16_MIN 0x8000
#define INT16_MAX 0x7FFF

#define UINT16_MIN 0x0000
#define UINT16_MAX 0xFFFF

#define INT32_MIN 0x80000000
#define INT32_MAX 0x7FFFFFFF

#define UINT32_MIN 0x00000000
#define UINT32_MAX 0xFFFFFFFF

#define INT64_MIN 0x8000000000000000
#define INT64_MAX 0x7FFFFFFFFFFFFFFF

#define UINT64_MIN 0x0000000000000000
#define UINT64_MAX 0xFFFFFFFFFFFFFFFF
#endif

typedef unsigned char       Bool;
typedef signed char         Int8;
typedef unsigned char       UInt8;
typedef signed short        Int16;
typedef unsigned short      UInt16;
typedef signed long         Int32;
typedef unsigned long       UInt32;
typedef signed long long    Int64;
typedef unsigned long long  UInt64;
typedef float               Float32;
typedef long float          Float64;
typedef double              Double;


Int32 sum_s32s32_s32(Int32 a_s32, Int32 b_s32)
{
	Int64 result_s64 = (Int64)a_s32 + (Int64)b_s32;
	Int32 result_s32 = 0;

	/* Range of Saturation: INT32_MIN ~ INT32_MAX */
	if (result_s64 < INT32_MIN) {
		result_s32 = INT32_MIN;
	}
	else if (INT32_MAX < result_s64) {
		result_s32 = INT32_MAX;
	}
	else {
		result_s32 = (Int32)result_s64;
	}

	return result_s32;
}

Int32 sub_s32s32_s32(Int32 a_s32, Int32 b_s32)
{
	Int64 result_s64 = (Int64)a_s32 - (Int64)b_s32;
	Int32 result_s32 = 0;

	/* Range of Saturation: INT32_MIN ~ INT32_MAX */
	if (result_s64 < INT32_MIN) {
		result_s32 = INT32_MIN;
	}
	else if (INT32_MAX < result_s64) {
		result_s32 = INT32_MAX;
	}
	else {
		result_s32 = (Int32)result_s64;
	}

	return result_s32;
}

Int32 mul_s32s32_s32(Int32 a_s32, Int32 b_s32)
{
	Int64 result_s64 = (Int64)a_s32 * (Int64)b_s32;
	Int32 result_s32 = 0;

	/* Range of Saturation: INT32_MIN ~ INT32_MAX */
	if (result_s64 < INT32_MIN) {
		result_s32 = INT32_MIN;
	}
	else if (INT32_MAX < result_s64) {
		result_s32 = INT32_MAX;
	}
	else {
		result_s32 = (Int32)result_s64;
	}

	return result_s32;
}

Int32 div_s32s32_s32(Int32 a_s32, Int32 b_s32)
{
	Int64 result_s64 = (Int64)a_s32 / (Int64)b_s32;
	Int32 result_s32 = 0;

	/* Range of Saturation: INT32_MIN ~ INT32_MAX */
	if (result_s64 < INT32_MIN) {
		result_s32 = INT32_MIN;
	}
	else if (INT32_MAX < result_s64) {
		result_s32 = INT32_MAX;
	}
	else {
		result_s32 = (Int32)result_s64;
	}

	return result_s32;
}

void main()
{
#if 1
	Bool     var_b   = 1;
	Int8     var_i8  = INT8_MIN;
	UInt8    var_u8  = UINT8_MAX;
	Int16    var_s16 = INT16_MIN;
	UInt16   var_u16 = UINT16_MAX;
	Int32    var_s32 = INT32_MIN;
	UInt32   var_u32 = UINT32_MAX;
	Int64    var_s64 = INT64_MIN;
	UInt64   var_u64 = UINT64_MAX;
	Float32  var_f32 = 0.15;
	Float64  var_f64 = 2.23456787;
	Double   var_d   = 1234.567890123456789;
#endif

	char print_c[255] = "abcdefg.";
#if 0 /* rule of input parameters on command window */
	char input_c[255] = "";

	Int32 input_s32;
	
	printf("입력 받을 값: ");
	scanf("%d", &input_s32);
	printf("입력 받은 값: %d\n\n", input_s32);

	printf("입력 받을 문자열: ");
	scanf("%s", &input_c);
	printf("입력 받은 문자열: %s\n\n", input_c);
#endif

#if 0 /* size of types */
	printf("size of bool:    %d\n", sizeof(bool));
	printf("size of Bool:    %d\n", sizeof(Bool));
	printf("size of Int8:    %d\n", sizeof(var_i8));
	printf("size of UInt8:   %d\n", sizeof(UInt8));
	printf("size of Int16:   %d\n", sizeof(var_s16));
	printf("size of UInt16:  %d\n", sizeof(var_u16));
	printf("size of Int32:   %d\n", sizeof(var_s32));
	printf("size of UInt32:  %d\n", sizeof(var_u32));
	printf("size of Int64:   %d\n", sizeof(var_s64));
	printf("size of UInt64:  %d\n", sizeof(var_u64));
	printf("size of Float32: %d\n", sizeof(Float32));
	printf("size of Float64: %d\n", sizeof(var_f64));
	printf("size of Double:  %d\n", sizeof(var_d));
#endif

#if 1 /* value of variables */
	printf("value of var_b:\t\t%d\n", var_b);
	printf("value of var_i8:\t%d\n", var_i8);
	printf("value of var_u8:\t%d\n", var_u8);
	printf("value of var_s16:\t%d\n", var_s16);
	printf("value of var_u16:\t%d\n", var_u16);
	printf("value of var_s32:\t%d\n", var_s32);
	printf("value of var_u32:\t%d\n", var_u32);
	printf("value of var_s64:\t%lld\n", var_s64);
	printf("value of var_u64:\t%lld\n", var_u64);

	printf("value of var_f32(f):\t%f\n", var_f32);
	printf("value of var_f32(e):\t%e\n", var_f32);
	printf("value of var_f32(.3f):\t%.3f\n", var_f32);

	printf("value of var_d(lf):\t%lf\n", var_d);
	printf("value of var_d(le):\t%le\n", var_d);
	printf("value of var_d(.20lf):\t%.20lf\n", var_d);

	printf("value of print_c:\t%c\n", print_c[0]);
	printf("value of print_c:\t%s\n", print_c);
#endif
}
