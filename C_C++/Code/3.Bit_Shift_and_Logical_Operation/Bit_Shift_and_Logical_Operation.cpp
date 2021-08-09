#include<stdio.h>

void typeCasting(void);
void DataTransfer_1(void);
void DataTransfer_2(void);

int main(void)
{
	typeCasting();
	DataTransfer_1();
	DataTransfer_2();
	return 0;
}

void typeCasting(void)
{
	signed char a = 0xff;
	unsigned char b = 255;

	printf("a = b : %d\n", a);
}

void DataTransfer_1(void)
{
	printf("---------------------DataTransfer_1-----------------------\n");
	signed short a = 3500;
	unsigned char send[2];
	send[0] = a >> 8;
	send[1] = a & 0xff;

	printf("send[0] decimal = %d, hex = %x\n", send[0], send[0]);
	printf("send[1] decimal = %d, hex = %x\n", send[1], send[1]);

	unsigned char recv[2];
	recv[0] = send[0];
	recv[1] = send[1];

	signed short b = 0x00;
	unsigned short c = (recv[0] << 8) | (recv[1] & 0xff);
	b = c;
	printf("c decimal = %d, hex = %x\n", c, c);
	printf("b decimal = %d, hex = %x\n", b, b);
}

void DataTransfer_2(void)
{
	printf("---------------------DataTransfer_2-----------------------\n");
	signed int a = 1000000;
	unsigned char send[4];
	send[0] = (a >> (8 * 3)) & 0xff ;
	send[1] = (a >> (8 * 2)) & 0xff;
	send[2] = (a >> (8)) & 0xff;
	send[3] = (a & 0xff);

	printf("send[0] decimal = %d, hex = %x\n", send[0], send[0]);
	printf("send[1] decimal = %d, hex = %x\n", send[1], send[1]);
	printf("send[3] decimal = %d, hex = %x\n", send[2], send[2]);
	printf("send[4] decimal = %d, hex = %x\n", send[3], send[3]);
	printf("--------------------------------------------------\n");

	signed int b;
	unsigned char recv[4];
	recv[0] = send[0];
	recv[1] = send[1];
	recv[2] = send[2];
	recv[3] = send[3];

	b = 0x00;
	b = (recv[0] << (8 * 3)) | (recv[1] << (8 * 2))| (recv[2] << (8))| recv[3];

	printf("recv[0] decimal = %d, hex = %x\n", recv[0], recv[0]);
	printf("recv[1] decimal = %d, hex = %x\n", recv[1], recv[1]);
	printf("recv[3] decimal = %d, hex = %x\n", recv[2], recv[2]);
	printf("recv[4] decimal = %d, hex = %x\n", recv[3], recv[3]);
	printf("b decimal = %d, hex = %x\n", b, b);
}