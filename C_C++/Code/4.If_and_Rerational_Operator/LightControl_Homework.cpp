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

#define AA 0b0001 /* 604ȣ */
#define AB 0b0010 /* 603ȣ */
#define AC 0b0100 /* ȸ�ǽ� */
#define AD 0b1000 /* ������Ʈ��B */

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
		printf("0 :  ��ü\t 1 : 604ȣ\t 2 :  603ȣ\t 3 :  ȸ�ǽ�\t 4 : ������Ʈ��B\n");
		printf("------------------------------------------------------------------------\n");
		printf("�� ��ȣ�� �Է��ϼ���! :");
		scanf("%d", &roomNum);

		if ((0 <= roomNum) && (roomNum <= 5) == false)
		{
			printf("�ش��ϴ� ���� �������� �ʽ��ϴ�.\n");
			continue;
		}

		printf("\n");
		printf("\n");
		printf("---------------------------------------------\n");
		printf("1 : �� �ѱ�\t 0 : �Ҳ���\n");
		printf("----------------------------------------------\n");

		switch (roomNum)
		{
		case 0:
			printf("��ü ���� ���� ���¸� �����ϼ���: ");
			break;
		case 1:
			printf("604ȣ ���� ���� ���¸� �����ϼ���: ");
			break;
		case 2:
			printf("603ȣ ���� ���� ���¸� �����ϼ���: ");
			break;
		case 3:
			printf("ȸ�ǽ� ���� ���� ���¸� �����ϼ���: ");
			break;
		case 4:
			printf("������Ʈ��B ���� ���� ���¸� �����ϼ���: ");
			break;
		case 5:
			break;
		}

		scanf("%d", &lightState);

		if ((0 <= lightState) && (lightState <= 1) == false)
		{
			printf("���� ���¸� ������ �� �����ϴ�.\n");
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
		printf("604ȣ : on\t");
	}
	else
	{
		printf("604ȣ : off\t");
	}

	if ((currentLight & 0x02) == 0x02)
	{
		printf("603ȣ : on\t");
	}
	else
	{
		printf("603ȣ : off\t");
	}

	if ((currentLight & 0x04) == 0x04)
	{
		printf("ȸ�ǽ� : on\t");
	}
	else
	{
		printf("ȸ�ǽ� : off\t");
	}

	if ((currentLight & 0x08) == 0x08)
	{
		printf("������Ʈ��B : on\t");
	}
	else
	{
		printf("������Ʈ��B : off\t");
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