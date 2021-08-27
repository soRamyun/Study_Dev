# C언어 C++ 기초

## 0. 목차

1. [자료구조와 이해](#1-자료구조와-이해)
   
   1.1 [비트표현](#11-비트표현)
   
   1.2 [자료형](#12-자료형)
   
   1.3 [sizeof](#13-sizeof)
   
   1.4 [Type Casting](#14-Type-Casting)
   
   1.5 [Parameter와 Argument](#15-Parameter와-Argument)
   
   1.6 [헝가리안 표기법](#16-헝가리안-표기법)
   
2. [연산](#2-연산)

   2.1 [사칙연산과 Saturation](#21-사칙연산과-Satucation)

   2.2 [bit 연산](#22-bit-연산)

   2.3 [논리연산](#23-논리연산)
   
   2.4 [관계연산](#24-관계연산)
   
   2.5 [종합예시](#25-종합-예시)

3. [표준 입출력](#3-표준-입출력)

   3.1 [출력함수](#31-출력함수)
   
   3.2 [입력함수](#32-입력함수)

4. [제어문](#4-제어문)

   4.1 [if문](#41-if-else-if-else)
   
   

## 1. 자료구조와 이해

#### 1.1비트표현 

- Bit -1bit 
- Nibble - 4bit 
- Byte - 8bit

#### 1.2 자료형

##### 1.2.1 자료형 종류

<img src="https://t1.daumcdn.net/cfile/tistory/2636724C5783428411" title="Data Type" alt="Data Type"></img>

- 임베디드시스템에서는 실수형에서 double을 많이 사용. 
- float는 메모리 자원이 한정적인 경우 자주 사용.
- int, float는 32bit, 64bit, 시스템마다 다른  크기를 가질 수 있다. 

##### 1.2.2  출력형식

| 출력형식 | 설명        | 예                   |
| -------- | ----------- | -------------------- |
| %c       | 문자열 하나 출력 | printf(""%c\n", 'a'); |
| %d       | 정수형 출력 | printf(""%d\n", 40); |
| %p       | 주소 출력 | printf(""%p\n", &p); |
| %x       | 16진수를 소문자로 출력 | printf(""%x\n", 127); |
| %X       | 16진수를 대문자로 출력 | printf(""%X\n", 127); |
| %o       | 8진수 출력 | printf(""%o\n",8888); |
| %s       | 문자열 출력 | printf(""%s\n","Study"); |
| %u       | unsigned int 출력 | printf(""%u\n",1);<br>printf(""%u\n",1);</br> |
| %ld       | long형 출력 | printf(""%ld\n",1L); |
| %lld       | long long형 출력 | printf(""%lld\n", 5294967295)); |
| %f       | float형 출력 | printf(""%f\n",0.1234f); |
| %lf       | double형 출력 | printf(""%lf\n",0.1234567f); |
| %e       | 실수를 지수표기법으로 표시 | printf(""%e\n",0.1234); |

- ```C
  printf(""%u\n",1);
  printf(""%u\n",-1);
  ```

  ```
  1
  4294967295
  ```

  1을 2의보수를 취하면 -1이 된다. 즉, 0000 0000 0000 0000 0000 0000 0000 0001 -> 1111 1111 1111 1111 1111 1111 1111 1110 + 1-> 1111 1111 1111 1111 1111 1111 1111 1111 = 4294967295이 출력값이 된다.

- ```C
  printf(""%e\n",0.1234);
  ```

  ```
  1.234e-01
  ```

##### 1.2.3 typedef

자료형과 구조체에 별칭을 달아서 사용할 수 있게 해준다.

```c
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
```

unsigned char를 대신하여 UInt8로 사용할 수 있도록 해준다.

#### 1.3 sizeof

자료형의 크기를 반환해 준다.

```
int ia;

printf("char = %d\n", sizeof(char));
printf("int = %d\n", sizeof(int));
printf("float = %d\n", sizeof(float));
printf("double = %d\n", sizeof(double));

printf("ia = %d", sizeof(ia));
```

#### 1.4 Type Casting

자료형이 다른 변수에 값을 대입할때 (자료형)을 사용하여 형을 변환한다.

```
int ia;
float fb = 1;

ia = (int)fb;
```

다만 가이드라인에서는 float, int타입 casting을 지양한다. 

#### 1.5 Parmeter와 Argument

```
int sum(int a, int b)
{
	return a+b;
}

int main(void)
{
	int ia = 3;
	int ib = 4;
	
	sum(ia, ib);
}
```

- Parameter - 함수의 인자로 전달되는 변수의 값, sum 함수의 a,b가 parameter
- Argument - 함수의 인자로 전달되는 변수, mian에서 sum(ia, ib)에 사용된 ia,ib가 argument이다.

#### 1.6 헝가리안 표기법

변수앞에 자료형을 뜻하는 값을 붙여서 표기

```
int ia, na, i8a, i16a;
float fb;
double dc;
```

- `int ia`와 같이 표기법을 앞에 붙이면 Prefix, `unsigned int var_ui8`과 같이 표기법을 뒤에 붙이면 Postfix라고 한다.

## 2. 연산

#### 2.1 사칙연산과 Saturation

##### 2.1.1 더하기

```c
typedef signed long         Int32;
typedef signed long long    Int64;

Int32 sum_s32s32_s32(Int32 a_s32, Int32 b_s32)
{
    /*Int32 a_s32 = INT32_MAX, Int32 b_s32 = INT32_MAX이면,
    	32bit의 최대값을 넘어가기 때문에 INT64로 형변환*/
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
```

빼기와 곱하기는 더하기와 같은방식으로 진행된다.

##### 2.1.2 나누기

```C
Int32 div_s32s32_s32(Int32 a_s32, Int32 b_s32)
{ 
    /*divide by zero*/
    if(b_s32 == 0) return 0;
    
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
```

- 덧셈, 뺄셈, 곱셈과 다르게 나누기는 <span style="color:red;">0으로 나누는 경우 </span>예외처리해줘야한다. 왜냐하면 %이란 값에서 '뺄셈의 반복'인데 0을 뺄셈해도 값은 변하지 않아 연산의 의미가 사라지고 몫이 ∞가 되기 때문이다. 
- 예외처리를 해주지 않을경우, b_s32가 0이라면 Exception오류가 발생한다. 

#### 2.2 bit 연산

##### 2.2.1 부호 bit

컴퓨터에서는 맨앞 1개의 비트트 부호비트로 사용한다. 0이면 양수, 1이면 음수를 의미한다.


##### 2.2.2 bit Shift

```
usigned int uia= 4;

printf(" 4 << 2 bit shift  = %d\n", uia << 2);
printf("4 >> 1 bit shift = %d\n", uia >> 1 );
```

```
16
2
```

- uia << n으 uia *  2^n을 의미한다. 즉 한 bit가 왼쪽으로 shift될 때마다 2가 곱해진다.
- uia >> n은 uia * 1/2^n을 의미한다. 즉 한 bit가 오른쪽으로 shift될때마다 1/2가 곱해진다.
- 이때 부호비트가 1인경우 >>했을 때, bit가 1로 채워지고, 그 외에는 0으로 채워진다.
- 가이드라인에서는 signed 자료형의 bit shift 사용을 지양한다. 
- 가이드라인에서는 정수형만 bit연산을 사용을 지향한다. 실수형은 실수와 가수부분으로 나누어져있기 때문에 shift가 발생하면 값을 알수없게 된다.

##### 2.2.3 음수 bit 표현

```
예시 : -10

10 : 0000 1010

1의 보수 : 1111 0101
2의 보수 : 1111 0101 + 0000 0001 = 1111 0110
Hex값 : 0xF6  
```

- 2의 보수를 취해서 음수를 표현한다. 
- 2의 보수는 1의 보수 + 1이다. 1의 보수는 0->1로 1->0으로 치환하여 표현한다.

#### 2.3 논리연산

| 연산자 | 설명 |
| ------ | ---- |
| &&     | AND(논리곱), 양쪽 모두 참일 때 참 |
| \|\| |OR(논리합), 양쪽 중 한쪽만 참이라도 참|
| !     |  Not(논리부정), 참과 거짓을 뒤집음    |

##### 2.3.1 AND(&)

| A    | B    | A and B |
| ---- | ---- | ------- |
| 0    |   0   |   0      |
| 0    |   1   |   0      |
| 1    |   0   |   0      |
| 1    |   1   |   1      |

##### 2.3.2 OR(|)

| A    | B    | A and B |
| ---- | ---- | ------- |
| 0    |   0   |   0      |
| 0    |   1   |   1      |
| 1    |   0   |   1      |
| 1    |   1   |   1      |

##### 2.3.3 NOT

| A   | ~A |
| ---- | ---- |
| 0    |   1   |
| 1    |   0   |

##### 2.3.4 A &(B|C)

| A    | B    | C    | B&C  | Result |
| ---- | ---- | ---- | ---- | ------ |
|     0|     0|     0|    0 |       0|
|     0|     0|     1|    1 |       0|
|     0|     1|     0|    1 |       0|
|     0|     1|     1|    1 |       0|
|     1|     0|     0|    0 |       0|
|     1|     0|     1|    1 |       1|
|     1|     1|     0|    1 |       1|
|     1|     1|     1|    1 |       1|

##### 2.3.5 A|(B&C)

| A    | B    | C    | (B or C) | Result |
| ---- | ---- | ---- | -------- | ------ |
|      |      |      |          |        |
|     0|     0|     0|        0 |       0|
|     0|     0|     1|        0 |       0|
|     0|     1|     0|        0 |       0|
|     0|     1|     1|        1 |       1|
|     1|     0|     0|        0 |       1|
|     1|     0|     1|        0 |       1|
|     1|     1|     0|        0 |       1|
|     1|     1|     1|        1 |       1|

#### 2.4 관계연산

| 연산자 | 사용 예시 | 설명                |
| ------ | --------- | ------------------- |
| <      | a < b     | a가 b보다 미만이다. |
| >      | a > b     | a가 b보다 초과이다. |
| <=     | a <= b    | a가 b보다 이하이다. |
| >=     | a >= b    | a가 b보다 이상이다. |
| ==     | a == b    | a가 b와 같다.       |
| =!     | a =! b    | a가 b와 같지 않다.  |
| !      | !a        | a가 아니다.         |
| ~      | ~a        | a의 1의 보수        |

- `~a` 만약 a가 0000 0001이면 ~a는 1111 1110으로 반전시킨 것이다.

#### 2.5 종합 예시

##### 2.5.1 정수를 1byte기준으로  비트로 나누어 저장하기

```C
Int16 ia = 3500;
Uint8 send[2];
send[0] = ia >> 8;
send[1] = ia & 0xff;

printf("send[0] decimal = %d, hex = %x\n", send[0], send[0]);
printf("send[1] decimal = %d, hex = %x\n", send[1], send[1]);

Int8 recv[2];
recv[0] = send[0];
recv[1] = send[1];

Int8 ib = 0x00;
ib = (recv[0] << 8) | (recv[1] & 0xff);
printf("b decimal = %d, hex = %x\n", ib, ib);
```

 ```C
 send[0] decimal = 13, hex = d
 send[1] decimal = 172, hex = ac
 b decimal = 3500, hex = dac
 ```

- 데이터 통신에서 자주 사용되는 비트 Shift, 논리 연산 예시이다.

- ia값을 send에 8비트씩 분리한다.

  - ia = 3,500 ------binary------> 0000 1101 1010 1100
  - send[0]은 ia >> 8을 하면 0000 0000 0000 1101이기 때문에 ia의 앞 8개 비트(0000 1101)를 저장한다.
  - send[1]은 뒤 8개 비트(1010 1100)를 저장한다.     

- ib는 8비트씩 분리된 비트 논리연산을 통해 합친다.

  - recv[0] << 8은 0000 1101 0000 0000이고, recv[1] & 0xff는 0000 0000 1010 1100

  - ​          0000 1101 0000 0000 

    OR    0000 0000 1010 1100

    `-------------------------------------`

    ​         0000 1101 1010 1100

## 3. 표준 입출력

#### 3.1 출력함수

##### 3.1.1 printf

```C
printf("Hello world!");
```

```C
Hello world!
```

- <stdio.h> 헤더파일에 정의되어있다.

- printf와 사용되는 이스케이프 시퀀스는 아래와 같다.

  | 특수문자 | 의미 | 설명 |
  | -------- | ---- | ---- |
  | \a      | 경고(alert)                |경고음 소리 발생  				|
  | \b      | 백스페이스(Backspace) 		 |백스페이스       				|
  | \f      | 폼피드(Form Feed)       	   |커서를 다음 페이지의 시작부분으로 넘김|
  | \n      | 개행(New line)     			|커서를 다음 줄 첫 번째 위치로 넘김|
  | \r      | 캐리지 리턴(Carriage Return) |커서를 다음줄로 넘기지 않고 첫 번째 위치로 넘김|
  | \t      | 수평탭     					|키보드의 tab 키와 같은 기능|
  | \v      | 수직탭     					|수직으로 탭|
  | \\      | 역슬래시     				    |백슬래시를 표기한다.|
  | \'      | 작은따음표     			   | 작음따음표를 출력|
  | \'      | 큰따음표     					| 큰따음표 출력|

  - \r은 옛날 타자기에서 한 줄을 다 쓰고 종이를 오른쪽으로 옮기는 작업을 생각하면 된다. 옛날에는 \n만하면 맨앞으로 안가고 바로 아래에 밑 칸으로 간다고 생각했지만 현재는 \n을 하면 \n\r의 효과가 있기 때문에 잘 사용되지 않는다.

#### 3.2 입력함수

##### 3.2.1 scanf

```C
/*scanf_s가 아닌 scanf를 사용할 때 #define _CRT_SECURE_NO_WARNINGS를 헤더보다 위에 작성*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int a;
scanf("정수 a값을 입력하세요 : %d", &a);
```

- <stdio.h> 헤더파일에 정의되어있다.
- scanf를 사용하면 사용자의 입력을 받을 때 까지 커서가 깜박거린다.
- a값을 a의 주소에 저장하기 때문에 &a를 사용하여 값을 받는다.

## 4. 제어문

#### 4.1 if-else if-else

```c
if(20 <= A){
   printf("A는 20이상이다.\n");
}
else if(10 <= A)
{
    printf("A는 10이상 20미만이다.\n");
}
else
{
    printf("A는 10미만이다.\n");
}
```

#### 4.2 Switch-Case

```C
int a = 0;
switch(a){
    case 1:
        printf("a값은 1입니다.\n");
		break;
	case 2:
        printf("a값은 1입니다.\n");
        break;
	default:
        printf("a는 1과2 둘 다 아닙니다.\n");
        break;
}
```

- Switch문을 if문으로 대체할 수 있다. 

```C
int a = 0;

if(a == 1)
{
	printf("a값은 1입니다.\n");    
}
else if(a == 2)
{
    printf("a값은 2입니다.\n");  
}
else
{
    printf("a는 1과2 둘 다 아닙니다.\n");
}
```

- Switch문은 if문과 다르게 <=, >=, <. > 등 비교행위는 할 수 없다. 즉, Switch을 if문으로 바꿀 수 없는 경우가 있다.
- Switch-Case문에서 각 case안에 break가 없을 시 만족하는 case문 아래 모든 case를 전부 돌게 된다.

```C
int a = 1;
switch(a){
    case 1:
        printf("a값은 1입니다.\n");
	case 2:
        printf("a값은 2입니다.\n");
	default:
        printf("a는 1과2 둘 다 아닙니다.\n");
}
```

```
a값은 1입니다.
a값은 2입니다.
a는 1과2 둘 다 아닙니다.
```



#### 4.3 종합 예제

##### 4.3.1 비트마스크를 사용하여 방의 불이 켜져있는 지 확인

```C
#define AA 0b0001 /* 604호 */
#define AB 0b0010 /* 603호 */
#define AC 0b0100 /* 회의실 */
#define AD 0b1000 /* 프로젝트룸B */

void detectLight(UInt8 light)
{
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

void main()
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

	detectLight(light);

	printf("\n");
	printf("\n");
	printf("\n");
```

- `UInt8 light = AA | AB | AC | AD`를 하면  light = 0000 1111값이 저장된다.  
- 불을 끄는 경우
  - `light = light & (~AA)`를 하면 0000 1111 & 1111 1110 = 0000 1110이된다. 이때 `if ((light & AA) != 0)`를 하면 0000 1110 & 0000 0001= 0000 0000이기 때문에 0과 같지 않기 때문에 `else{printf("604호 : Off.\n");}`를 만족하여 불이 꺼져있다고 화면에 출력하게 된다.

- 불을 키는 경우
  - `light = light | AA`를 하면 0000 1111으로 변화가 없다. 이때 `if ((light & AA) != 0)`를 하면 0000 1111  & 0000 0001 = 0000 0001로 0과 같기 때문에 if문을 만족하여 불이 켜져있다고 화면에 출력하게 된다.

## 5. 반복문

#### 4.1 for문



## 참고사이트

[자료형](https://lovelyoverflow.tistory.com/15)

[[C언어] 출력 형식 총정리](https://reakwon.tistory.com/169)