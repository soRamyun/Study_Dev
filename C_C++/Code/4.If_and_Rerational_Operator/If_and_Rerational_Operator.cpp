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
#define AA 0x01 /* 604ȣ */
#define AB 0x02 /* 603ȣ */
#define AC 0x04 /* ȸ�ǽ� */
#define AD 0x08 /* ������Ʈ��B */
#else
#define AA 0b0001 /* 604ȣ */
#define AB 0b0010 /* 603ȣ */
#define AC 0b0100 /* ȸ�ǽ� */
#define AD 0b1000 /* ������Ʈ��B */
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
	/*A�� 30���� �۰�, B�� A���� ũ��, C�� A�� ����Ѵ�.*/
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
	/*���濡 ���� �����ִ��� Ȯ���ϴ� �Լ��� ������.*/
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
		/* AA�� ���� ���� �ڵ� */
		light = light & (~AA);
	}
	{
		/* AA�� ���� �Ѵ� �ڵ� */
		//light = light | AA;
	}
	printf("\n");
	printf("\n");
	printf("\n");

	if ((light & AA) != 0) {
		printf("604ȣ : On.\n");
	}
	else {
		printf("604ȣ : Off.\n");
	}

	if ((light & AB) != 0) {
		printf("603ȣ\t\t: On.\n");
	}
	else {
		printf("603ȣ\t\t: Off.\n");
	}

	if ((light & AC) != 0) {
		printf("ȸ�ǽ�\t\t: On.\n");
	}
	else {
		printf("ȸ�ǽ�\t\t: Off.\n");
	}

	if ((light & AD) != 0) {
		printf("������Ʈ��B\t: On.\n");
	}
	else {
		printf("������Ʈ��B\t: Off.\n");
	}
}