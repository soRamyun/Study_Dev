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

#define AA 0b0001 /* 604호 */
#define AB 0b0010 /* 603호 */
#define AC 0b0100 /* 회의실 */
#define AD 0b1000 /* 프로젝트룸B */

void changeLight(int roomNum, int lightState);
void currentLightState();
void printBinary();

UInt8 currentLight = 0x00;

int main(void) 
{
	char exit = ' ';
	int roomNum = -1;
	int lightState = 0;
	
	int num = 0;
	while(num < 10) 
	{
		printf("\n");
		printf("\n");
		printf("---------------Start-------------------------------------------------\n");
		printf("\n");
		printf("\n");

		printBinary();
		currentLightState();
		printf("\n");
		printf("\n");

		printf("---------------Room number----------------------------------------------\n");
		printf("0 :  전체\t 1 : 604호\t 2 :  603호\t 3 :  회의실\t 4 : 프로젝트룸B\n");
		printf("------------------------------------------------------------------------\n");
		printf("방 번호를 입력하세요! :");
		scanf("%d", &roomNum);

		if ((0 <= roomNum) && (roomNum <= 5) == false)
		{
			printf("해당하는 방이 존재하지 않습니다.\n");
			continue;
		}

		printf("\n");
		printf("\n");
		printf("---------------------------------------------\n");
		printf("1 : 불 켜기\t 0 : 불끄기\n");
		printf("----------------------------------------------\n");

		switch (roomNum)
		{
		case 0:
			printf("전체 방의 불의 상태를 결정하세요: ");
			break;
		case 1:
			printf("604호 방의 불의 상태를 결정하세요: ");
			break;
		case 2:
			printf("603호 방의 불의 상태를 결정하세요: ");
			break;
		case 3:
			printf("회의실 방의 불의 상태를 결정하세요: ");
			break;
		case 4:
			printf("프로젝트룸B 방의 불의 상태를 결정하세요: ");
			break;
		case 5:
			break;
		}

		scanf("%d", &lightState);

		if ((0 <= lightState) && (lightState <= 1) == false)
		{
			printf("불의 상태를 결정할 수 없습니다.\n");
			continue;
		}

		changeLight(roomNum, lightState);
		num++;
	}

	return 0;
}

void printBinary()
{
	printf("current Bit flag : \t");
	UInt8 filter = 0x80;

	for (int i = 0; i < 8; i++) {

		if (i % 4 == 0) {
			printf("  ");
		}

		if ((currentLight & filter) == 0)
		{
			printf("%d", 0);
		}
		else
		{
			printf("%d", 1);
		}

		filter = filter >> 1;
	}
	printf("\n");
}

void currentLightState()
{

	printf("current Room Light : \t");

	if ((currentLight & 0x01) == 0x01)
	{
		printf("604호 : on\t");
	}
	else
	{
		printf("604호 : off\t");
	}

	if ((currentLight & 0x02) == 0x02)
	{
		printf("603호 : on\t");
	}
	else
	{
		printf("603호 : off\t");
	}

	if ((currentLight & 0x04) == 0x04)
	{
		printf("회의실 : on\t");
	}
	else
	{
		printf("회의실 : off\t");
	}

	if ((currentLight & 0x08) == 0x08)
	{
		printf("프로젝트룸B : on\t");
	}
	else
	{
		printf("프로젝트룸B : off\t");
	}

	printf("\n");
}

void changeLight(int roomNum, int lightState)
{

	if (roomNum == 0)
	{
		if (lightState == 1)
		{
			currentLight = 0x0f;
		}
		else
		{
			currentLight = 0x00;
		}		
	}
	else if (roomNum == 1)
	{
		if (lightState == 1)
		{
			currentLight = currentLight | AA;
		}
		else
		{
			currentLight = currentLight & (~AA);
		}
	}
	else if (roomNum == 2)
	{
		if (lightState == 1)
		{
			currentLight = currentLight | AB;
		}
		else
		{
			currentLight = currentLight & (~AB);
		}

	}
	else if (roomNum == 3)
	{
		if (lightState == 1)
		{
			currentLight = currentLight | AC;
		}
		else
		{
			currentLight = currentLight & (~AC);
		}
	}
	else
	{
		if (lightState == 1)
		{
			currentLight = currentLight | AD;
		}
		else
		{
			currentLight = currentLight & (~AD);
		}
	}
}