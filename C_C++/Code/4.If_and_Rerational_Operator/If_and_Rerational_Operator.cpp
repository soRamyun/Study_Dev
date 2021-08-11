#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

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

#if 0
#define AA 0x01 /* 604호 */
#define AB 0x02 /* 603호 */
#define AC 0x04 /* 회의실 */
#define AD 0x08 /* 프로젝트룸B */
#else
#define AA 0b0001 /* 604호 */
#define AB 0b0010 /* 603호 */
#define AC 0b0100 /* 회의실 */
#define AD 0b1000 /* 프로젝트룸B */
#endif

void Condition_Operation1();
void Condition_Operation2();
void detectLight();

int main(void)
{
	//Condition_Operation1();
	//Condition_Operation2();
	detectLight();
	return 0;
}

void Condition_Operation1()
{
	/*A가 30보다 작고, B가 A보다 크면, C에 A를 출력한다.*/
	int A = 20;
	int B = 30;
	int C = 0;

	if ((A < 30) && (A < B))
	{
		C = A;
		printf("C = %d\n", C);
	}
}

void Condition_Operation2()
{
	/*각방에 불이 켜져있는지 확인하는 함수를 만들어라.*/
	unsigned char light = AA | AB | AC | AD;

	if((light & 0x01) == 0x01)
	{
		printf("AA : on\n");
	}

	if ((light & 0x02) == 0x02)
	{
		printf("AB : on\n");
	}

	if ((light & 0x04) == 0x04)
	{
		printf("AC : on\n");
	}

	if ((light & 0x08) == 0x08)
	{
		printf("AD : on\n");
	}
	
}

void detectLight()
{
	UInt8 light = AA | AB | AC | AD;
	{
		/* AA의 불을 끄는 코드 */
		light = light & (~AA);
	}
	{
		/* AA의 불을 켜는 코드 */
		//light = light | AA;
	}
	printf("\n");
	printf("\n");
	printf("\n");

	if ((light & AA) != 0) {
		printf("604호 : On.\n");
	}
	else {
		printf("604호 : Off.\n");
	}

	if ((light & AB) != 0) {
		printf("603호\t\t: On.\n");
	}
	else {
		printf("603호\t\t: Off.\n");
	}

	if ((light & AC) != 0) {
		printf("회의실\t\t: On.\n");
	}
	else {
		printf("회의실\t\t: Off.\n");
	}

	if ((light & AD) != 0) {
		printf("프로젝트룸B\t: On.\n");
	}
	else {
		printf("프로젝트룸B\t: Off.\n");
	}
}