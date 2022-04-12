# C언어 C++ 기초

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

#### 1.5 헝가리안 표기법

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

#### 5.1 for문 

##### 5.1.1 for문 

```C
for(초기식 ; 조건식 ; 변화식)
{
    반복할 코드;
}
```

- 초기식: 반복문을 시작할 때 초기식입니다. 
- 조건식: 반복될 조건입니다. 조건식이 참이면 계속 반복하며, 거짓이 되면 반복문을 끝낸다.
- 변화식: 반복문이 한 번 실행될 때마다 수행할 식입니다.

```C
for(int i = 1; i <= 5; i++)
{
    printf("%d번째 반복문 실행\n", i);
}
```

```
1
2
3
4
5
```

- 초기식은 i=1이다.
- 조건식은 i가 5이하일 경우, 참 아닐경우, 거짓이다. 즉 i가 6이상이면 조건식을 만족하지 않아서 for문을 빠져나온다.
- 변화식은 i++(i = i+1이라는 의미)으로 반복문이 한번 실행될 때 i에 +1이 된다.

##### 5.1.2 다중 for문

```C
for(int i = 0; i < 3; i++)
{
    for(int j = 0; j < 3; j++)
    {
        printf("i = %d, j = %d\n", i, j);
    }
}
```

```
i = 0, j = 0
i = 0, j = 1
i = 0, j = 2
i = 1, j = 0
i = 1, j = 1
i = 1, j = 2
i = 2, j = 0
i = 2, j = 1
i = 2, j = 2
```

- 다중 for문은  맨 안쪽 for문이 다 돌고 나서 바깥쪽 for문이 하나씩 증가한다. 
- 예제 설명
  1. i = 0일 경우, j = 0,1,2 for을 3번 다 돈다.
  2. i = 1일 경우, j = 0,1,2 for을 3번 다 돈다.
  3. i = 2일 경우, j = 0,1,2 for을 3번 다 돈다.  
- 3중, 4중 for문의 경우도 for문의 개수만 차이가 있을 뿐 원리는 같다.

#### 5.2 종합예제

##### 5.2.1 구구단 

```C
for (int i = 1; i < 5; i++)
{
	for (int j = 2; j < 5; j++)
	{	
		printf("%d * %d = %d\t",j, i, (i * j));
	}
	printf("\n");
}
return 0;
```

```
2 * 1 = 2       3 * 1 = 3       4 * 1 = 4
2 * 2 = 4       3 * 2 = 6       4 * 2 = 8
2 * 3 = 6       3 * 3 = 9       4 * 3 = 12
2 * 4 = 8       3 * 4 = 12      4 * 4 = 16
```



## 6. 변수 선언 위치에 따른 차이

|                                            | 지역변수(local variable) | 전역변수(global variable)                     | 정적변수(static variable)                                    |
| ------------------------------------------ | ------------------------ | --------------------------------------------- | ------------------------------------------------------------ |
| 메모리 생성 시점                           | 중괄호 내부              | 프로그램 시작                                 | 프로그램 시작                                                |
| 메모리 소멸 시점                           | 중괄호 탈출              | 프로그램 종료                                 | 프로그램 종료                                                |
| 디폴트 초깃값<br>(초기화하지 않을 시)</br> | 쓰레기값 저장            | 자동 0 초기화                                 | 자동 0 초기화<br>(초기화는 한번만 진행)</br>                 |
| 사용범위                                   | 중괄호 내부              | 프로그램 전체                                 | -정적 지역변수<br>(static local variable)</br><br>:중괄호 내부</br><br></br><br>-정적 전역변수</br><br>(static global variable)</br><br>: 선언된 소스파일</br> |
| 메모리 할당 공간                           | Statck 영역              | Data  영역(초기화)<br>BSS 영역(비초기화)</br> | Data  영역(초기화)<br/>BSS 영역(비초기화)</br>               |

#### 6.1 지역변수(local variable)

```C
void increaseNumber()
{
    int num = 0;
    printf("num = %d\n", num);
    num++;
}

int mian()
{
    increaseNumber();
    increaseNumber();
    increaseNumber();
    increaseNumber();
}
```

```
num = 0
num = 0
num = 0
num = 0
```

- 지역변수의 **지역**은 함수의 내부, 중괄호 내부를 의미한다.따라서 지역변수는 중괄호 내부, 함수의 매개변수(Parameter)에서 사용되는 변수를 의미한다.
- 함수 내에서만 접근 가능하고 함수를 벗어나면 메모리 역영에서 소멸된다.
- 위 예제에서 num은 함수 increaseNumber에서만 사용되고 함수가 끝나면 소멸되기 된다. 즉, 함수를 호출할 때 num은 메모리에 할당되면서 0으로 초기화 되고,  함수가 끝나면 메모리에서 사라진다. 다시 호출했을 때 num은 메모리에 **다시** 할당되면서 0이 초기화 되고 함수가 끝나면 메모리에서 소멸된다.  때문에 여러번 호출해도 num은 0이 출력된다.

#### 6.2 전역변수(global variable)

```C
int num = 0;
void increaseNumber()
{   
    printf("num = %d\n", num);
    num++;
}

int mian()
{
    increaseNumber();
    increaseNumber();
    increaseNumber();
    increaseNumber();
}
```

```
num = 0
num = 1
num = 2
num = 3
```

- 전역변수는 중괄호 외부에서 선언되는 변수이다. 
- 전역변수를 프로그램이 시작됨과 동시에 메모리에 생성되어 프로그램이 종료되어야 메모리에서 사라지기 때문에 어느 지역에서든 참조해서 사용할 수 있다.
- 위 예제에서 num은 전역변수로 선언되었기때문에 함수 increaseNumber가 종료 되어도 값이 유지된다. 따라서 1씩 증가한 값이 출력된다.

#### 6.3 정적변수(static variable)

```C
extern static num2 = 0;
void increaseNumber()
{   
    static int num = 0;
    printf("num = %d\n", num);
    num++;
}

int mian()
{
    increaseNumber();
    increaseNumber();
    increaseNumber();
    increaseNumber();
    num++; // error
    num2++;
}
```

```
num = 0
num = 1
num = 2
num = 3
```

- 정적변수는 함수를 벗어나도 변수가 사라지지 않고 유지된다.
- 위 예제에서 num은 정적변수로 선언되었기때문에  increaseNumber 함수가 종료 되어도 값이 유지된다. 따라서 1씩 증가한 값이 출력된다.
- 전역변수와의  정적 지역변수 차이점은 정적 지역변수는 함수내에서 초기화가 한번만 되는 것이고, 함수 외부에서는 사용할 수 없다. 위 예제에서 main함수에서 increaseNumber함수의 정적변수를 사용할 수 없다. 
- 전역변수와 정적 전역변수는 파일 내 어느 지역에서든 사용가능하다는 공통점이 있다. 이 둘의 차이점은정적 전역변수는 extern(외부 파일 사용가능하게 하는 키워드)를 사용해도 외부파일에서는 사용이 불가능하다.

## 7. 배열

배열(Array)이란, 어떤 한가지 자료형을 연속적으로 나열하는 것을 의미한다.  

#### 7.1 배열 선언과 접근

```C
// 자료형 변수이름[개수]
int ia[5] = {1,2,3,4,5};
int phoneNum[2];
phoneNum[0] = 12341234;
phoneNum[1] = 12345678;

ia[6] = 6; //error
printf("%d\n", a[0]); // 첫 번째 값을 출력.
printf("%d\n", a[1]); // 두 번째 값을 출력.
printf("%d\n", a[2]); // 세 번째 값을 출력.
printf("%d\n", a[3]); // 네 번째 값을 출력.
printf("%d\n", a[4]); // 다섯 번째 값을 출력.
printf("%d\n", a[5]); //error 
```

```
1
2
3
4
5
```

- 배열을 선언할 때 int,char,double과 같이 자료형을 정해줘야한다. 왜냐하면 자료형이 사용하는 메모리의 공간크기가 다르기 때문에 정확한 크기를 할당하기 위해서 사용된다. **int ia[5]**의 경우 **"int형 4byte 크기의 공간을 5개 할당해줘!"**라는 의미로 20byte라는 메모리공간이 ia를 위해 할당된다.  
- 배열을 초기화 할때는 배열의 개수를 넘어서게 초기화 할 수 없다. 
- `int ia[5] = {1,2,3,4,5}`는 배열을 선언과 동시에 초기화한 경우다. phoneNum은 선언을 한 뒤, 초기화를 한 경우이다.
- 배열을 접근하는 방법은 index를 통해서 하게 된다.  index는 [ ]안의 숫자를 의미한다. 이때 index는 **0부터 시작한다.** 때문에 ia에 첫번째 값을 접근하려면 ia[0]으로 접근해야한다.

#### 7.2 배열과 for문

```C
int ia[5] = {10,20,30,40,50};

for(int i = 0; i < 5; i++){
    printf("%d번째 값 출력 %d\n", i+1, a[i]); 
}
```

```
1번째 값 출력 10
2번째 값 출력 20
3번째 값 출력 30
4번째 값 출력 40
5번째 값 출력 50
```

#### 7.3 문자열 배열

```C
char name[4] = 'KIM';
char name1[3] = 'KIM'; //error 발생
char name2[10] = {'P','a','r','k', '\0'};

printf("%s\n", name);
printf("%s\n", name2);
printf("%s\n", 'ABC\0DEF')
```

```
KIM
Park
ABC
```

- 문자열 배열은 char로 이루어진 배열이다. 
- 주의사항으로는 문자열 맨 뒤에는 **\0, NULL**문자가 들어가 삽입된다. 따라서 KIM은  **'KIM\0'** 총 4글자가 필요하기 때문에 name1은 에러가 발생한다.
- 문자열은 **\0**을 만날 때까지 출력하기 때문에 `printf("%s\n", 'ABC\0DEF')`은 ABC까지만 출력하게 된다.

#### 7.4 2차원 배열

```C
int ib[3][4] = {
    {1,2,3}, 
    {4,5,6}
};

printf("b[0]의 첫번째 값 = %d\n", ib[0][0]);
printf("b[0]의 두번째 값 = %d\n", ib[0][1]);
printf("b[0]의 세번째 값 = %d\n", ib[0][2]);
printf("b[1]의 첫번째 값 = %d\n", ib[1][0]);
printf("b[1]의 두번째 값 = %d\n", ib[1][1]);
printf("b[1]의 세번째 값 = %d\n", ib[1][2]);
```

```
b[0]의 첫번째 값 = 1
b[0]의 두번째 값 = 2
b[0]의 세번째 값 = 3
b[1]의 첫번째 값 = 4
b[1]의 두번째 값 = 5
b[1]의 세번째 값 = 6
```

- 2차원 배열은 행렬과 같은 방식으로 저장된다.

#### 7.5 2차원 배열과 이중 for문

```C
for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
        printf("b[%d]의 첫번째 값 출력 %d\n", i, j, ib[i][j]); 
    }
}
```

```
b[0]의 첫번째 값 = 1
b[0]의 두번째 값 = 2
b[0]의 세번째 값 = 3
b[1]의 첫번째 값 = 4
b[1]의 두번째 값 = 5
b[1]의 세번째 값 = 6
```

## 8. 포인터

## 9. 문자열

#### 9.1 문자열 선언

##### 9.1.1 배열

```C
//1. 문자의 길이를 알고 있는 경우의 선언
char szTextLine[13] = "Hello World!";
//2. 문자의 길이와 상관없이 선언
char szTextLine2[] = "Hellow World!";
//3. Null문자를 제외한 길이로 문자열 선언
char szTextLine3[12] = "Hello World!";

printf("szTextLine = %s\n", szTextLine);
printf("szTextLine2 = %s\n", szTextLine2);
printf("szTextLine3 = %s\n", szTextLine3); 
```

```
szTextLine = Hello World!
szTextLine2 = Hellow World!
szTextLine3 = Hello World!儆儆儆儆Hellow World!
```

- 1과 2 모두  stack메모리 공간에 13개의 공간이 할당된다. 왜냐하면 문자열의 마침을 알리는 Null의 자리가 포함되어야 하기 때문이다. 

| szTextLine1 | H    | e    | l    | l    | o    |      | W    | o    | r    | l    | d    | !    | \n   |
| ----------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| szTextLine2 | H    | e    | l    | l    | o    |      | W    | o    | r    | l    | d    | !    | \n   |

- 3의 출력값은 `Hello World!儆儆儆儆Hellow World!'`으로 쓰레기 값이 뒤에 더 붙어있다. 원인은 Null이 문자열의 마지막에 존재하지 않기 때문이다(Null이 들어갈 공간을 마련해주지 않았다). printf에서 %s는 Null문자를 만나면 문자열의 끝임을 알고 Null이전까지 출력하는데 만약 문자열 선언에서 Null의 공간이 없다면 stack메모리에서 Null을 만날때까지 출력한다. 때문에 쓰레기값`儆儆儆儆Hellow World!`이 같이 출력된다. 위의 경우, stack은 아래에서 위(높을주소에서 낮은주소)로 쌓이는 특징이 있어 szTextLine3이 szTextLine2의 Null까지 가서 출력이 멈췄기 때문에 Hellow World!가 두번 출력되었다.

##### 9.1.2 포인터

```C
char *szTextLine = "Hello World!";

printf("szTextLine = %s\n", szTextLine);
```

```
szTextLine = Hello World!
```

- 결과값이 정상으로 나오는 것으로 보아, 포인터로 문자열을 선언하면 맨 뒤에 자동으로 Null이 생성됨을 알 수 있다.

##### 9.1.3 배열 vs 포인터

```C
char szTextLine[] = "Hello World!";
char *ptr = "Hello World!";

//배열로 선언된 문자열 수정 가능
szTextLine[0] = 'h';
//에러발생! - 포인터로 선언된 문자열 수정 불가능
ptr[0] = 'h';
```

- 배열로 선언된 문자열의 경우, stack 메모리에 1byte씩 저장되어 있기때문에 수정이 가능하다

- 포인터로 선언된 문자열의 경우, "Hello World"는 Data 메모리에 저장되고, 그 Data 메모리에 저장된 첫번째 주소를 ptr이 가지고 있다. 즉 ptr은 상수를 가르키는 포인터가 되기 때문에 상수를 변경하려고 하니 문제가 발생한다.

  <img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FdO2dPJ%2Fbtq3bVaOz0V%2F99j6FqvSkqmfN42VIR9D4K%2Fimg.png" title="pointer vs array" alt="pointer vs array"></img>
##### 9.1.4 문자열 동적할당

```C
char* szTextLine;
szTextLine = (char*)malloc(sizeof(char) * 10);
sprintf(szTextLine, "abc");

printf("szTestLine = %s\n", szTextLine);

szTextLine[0] = 'A';
printf("szTestLine = %s\n", szTextLine);

free(szTextLine);
```

```
abc
Abc
```

- 포인터로 문자열을 동적할당을 하는 경우 Heap영역에 저장되기 때문에 수정가능하다.

#### 9.2 문자열 길이 구하기(strlen)

```C
char* szTextLine = "Hello";
char szTextLine2[10] = "Hello";

printf("szTextLine length = %d\n", strlen(szTextLine));
printf("szTextLine2 length = %d\n", strlen(szTextLine2));
```

```
5
5
```

- 문자열의 길이는 Null 부분은 포함하지 않는다.
- `char szTextLine2[10] = "Hello"`은 베열의 길이인 10을 출력하지 않고 Hello의 개수인 5를 출력한다. 

#### 9.3 문자열 비교(strcmp)

```C
printf("%d\n", strcmp("aaa", "aaa"));    //  0: aaa와 aaa는 같으므로 0
printf("%d\n", strcmp("aab", "aaa"));    //  1: aab와 aaa 중에서 aab가 크므로 1
printf("%d\n", strcmp("aaa", "aac"));    // -1: aab와 aac 중에서 aac가 크므로 -1
```

```
0
1
-1
```

- strcmp(s1, s2)

  -1: ASCII 코드 기준으로 문자열2(s2)가 클 때

  0: ASCII 코드 기준으로 두 문자열이 같을 때

  1: ASCII 코드 기준으로 문자열1(s1)이 클 때

#### 9.4 문자열 복사하기(strcpy)

```C
char szTextLine[10] = "Hello";
char szTextLine2[10] = "Hello";

strcmp(szTextLine, szTextLine2);

printf("szTextLine = %s\n", (szTextLine));
printf("szTextLine2 = %s\n", (szTextLine2));
```

```
szTextLine = Hello
szTextLine2 = Hello
```

- 문자열 포인터는 malloc으로 동적할당 후에 strcpy를 사용할 수 있다. 동적할당을 하지 않으면 `"Hello"`가 데이터 영역에 저장되어 실행파일이 실행된 뒤에는 읽기전용 메모리가 되어 쓰기를 할 수 없기 때문이다.

#### 9.5 문자열 자르기(strtok)

```C
char szWord[100];
memset(szWord, 0, sizeof(szWord)); //메모리 초기화, 할당된 메모리를 전부 9으로 초기화
sprintf(szWord, "Hello World!");

char* tok0 = strtok(szWord, " ");

while (tok0 != NULL)
{
	printf("tok0 = %s\n", tok0);
	tok0 = strtok(NULL, " ");
}
```

```
tok0 = Hello
tok0 = World!
```

- strtok는 지정된 문자를 기준으로 문자열을 자른다. 다만 잘린 문자열을 한번에 얻을 수 없어서 while문을 사용하여 문자열 끝에 있는 Null문자를 만나면 반복문을 끝낸다.

## 10. 함수

#### 10.1 함수 선언

```c
반환형 함수명(인자, 인자, ...)
{
	코드
}
```

```C
int sum(int a, int b)
{
	return a + b;
}
```

#### 10.2 Parmeter와 Argument

```C
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

#### 10.3 Call by value

```C
void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
    printf("swap : a = %d, b = %d\n", a, b);
}

void main()
{
    int a = 5;
    int b = 10;
    swap(a, b);
	printf("main : a = %d, b = %d\n", a, b);
}
```

```
swap : a = 10, b = 5
main : a = 5, b = 10
```

- swap함수는 a와 b의 값을 서로 바꿔서 저장하는 함수이다. 하지만 swap함수 내에서는 값이 변경되었지만 main함수의 a,b는 값이 변경되지 않는다.
- 함수의 parameter로 데이터를 전달할 때에는 복사본을 전달된다. 이 복사본의 값이 바뀌고 함수가 끝나면 사라지기 때문에 main함수의 값에는 영향을 미치지 못한다.

#### 10.4 Call by pointer

```C
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    printf("swap : a = %d, b = %d\n", a, b);
}

void main()
{
    int a = 5;
    int b = 10;
    swap(&a, &b);
	printf("main : a = %d, b = %d\n", a, b);
}
```

```
swap : a = 5, b = 10
main : a = 5, b = 10
```

- swap함수는 a와 b의 값을 서로 바꿔서 저장하는 함수이다. swap함수, main함수 모두  a,b는 값이 변경된 것을 알 수 있다.
- swap함수에 포인터를 사용하여 parameter a,b에 main함수 argument a,b의 주소값을 넘겨주면, swap함수의 argument  a, b는 전달받은  주소 번지의 값을 직접 바꾸기 때문에 swap, main에서 모두 값이 바뀌다.

## 11. 구조체

#### 11.1 구조체 선언

```C
typedef struct Address_tag {
	char name[10];
	char mobile[14];
	char address[50];
	char job[100];
	char age;
} Address, * pAddress;
```

#### 11.2 구조체 포인터

 ```c
 int main()
 {
     struct Address a1 = malloc(sizeof(Address));
     strcpy(a1->name, "홍길동");
     a1->age = 30;
     strcpy(a1->address, "서울시 용산구 한남동");
 	free(a1);  
 
     return 0;
 }
 ```

- 구조체 포인터에서 .으로 접근하려면 `(*a1).age`처럼 구조체 포인터를 역참조한 뒤 `.`으로 멤버에 접근한다.

#### 11.3 구조체 크기

```C
#include <stdio.h>

struct PacketHeader {
    char flags;    // 1바이트
    int seq;       // 4바이트
};

int main()
{
    struct PacketHeader header;

    printf("%d\n", sizeof(header.flags));           // 1: char는 1바이트
    printf("%d\n", sizeof(header.seq));             // 4: int는 4바이트
    printf("%d\n", sizeof(header));                 // 8: 구조체 전체 크기는 8바이트
    printf("%d\n", sizeof(struct PacketHeader));    // 8: 구조체 이름으로 크기 구하기

    return 0;
}
```

``` 
1
4
8
8
```

- C언어에서는 구조체를 정렬할 때 멤버 중에서 **가장 큰 자료형 크기의 배수**로 정렬한다. 여기서 가장 큰 자료형은 int이므로 4바이트 기준으로 정렬한다. 즉 5바이트를 채우기 위한 구조체의 크기는 **8바이트**가 된다. 이때 빈 공간을 채우는 것을 **패딩**이라고 부른다. 이 경우 패딩은 3바이트이이다.

#### 11.4 구조체와 메모리  초기화(memset)

```C
typedef struct Address_tag {
	char name[10];
	char mobile[14];
	char address[50];
	char job[100];
	char age;
} Address, * pAddress;

int main()
{
	pAddress pA1 = (pAddress)malloc(sizeof(Address));
	memset(pA1, 0, sizeof(Address));	//메모리를 0으로 전부 초기화
    
	printf("%d\n", pA1->age);

	free(pA1);
    return 0;
}
```

```
0
```

- `memset(구조체포인터, 설정할 값, sizeof(크기))`를 사용하면 메모리 내용을 한꺼번에 값을 설정할 수 있다.

#### 11.5 구조체와 메모리 복사(memcpy)

```C
#include <stdio.h>
#include <string.h> 

struct Point2D {
    int x;
    int y;
};

int main()
{
    struct Point2D p1;
    struct Point2D p2;

    p1.x = 10;    
    p1.y = 20;   

    memcpy(&p2, &p1, sizeof(struct Point2D));   

    printf("%d %d\n", p2.x, p2.y);   

    return 0;
}
```

```
10 20
```

- `memcpy(목적지포인터, 원본포인터, sizeof(크기))`을 사용하여 메모리의 내용을 다른 곳을 복사한다.

```C
int main()
{
    struct Point2D *p1 = malloc(sizeof(struct Point2D));
    struct Point2D *p2 = malloc(sizeof(struct Point2D));

    p1->x = 10;    
    p1->y = 20;    

    memcpy(p2, p1, sizeof(struct Point2D));    

    printf("%d %d\n", p2->x, p2->y);   

    free(p2);
    free(p1);

    return 0;
}
```

```
10 20
```

- 동적 메모리 복사는 위와 같다.

#### 11.6 구조체 포인터 배열

```C
struct Point2D {
    int x;
    int y;
};

int main()
{
    struct Point2D *p[3];   
    for (int i = 0; i < sizeof(p) / sizeof(struct Point2D *); i++) 
    {
        p[i] = malloc(sizeof(struct Point2D));    
    }

    for (int i = 0; i < sizeof(p) / sizeof(struct Point2D *); i++)    
    {
        free(p[i]);   
    }

    return 0;
}
```

#### 11.7  종합예제

##### 11.8 주소록 등록

```C
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int    Int;
typedef struct Address_tag {
	char name[10];
	char mobile[14];
	char address[50];
	char job[100];
	char age;
} Address, * pAddress;

void main()
{
	while (1) {

		char select;

		printf("create address book ? (y/n): ");
		scanf("%c", &select);

		if (select == 'y') {

			int num = 0;

			printf("how many ? ");
			scanf("%d", &num);

			pAddress* paddr = (pAddress*)malloc(sizeof(pAddress) * num);

			for (int i = 0; i < num; i++) {
				paddr[i] = (pAddress)malloc(sizeof(Address));
				memset(paddr[i], 0, sizeof(Address));

				printf("addr[%d]\n", i + 1);
				printf("\tname: ");
				scanf("%s", paddr[i]->name);
				printf("\tage: ");
				scanf("%d", &paddr[i]->age);
			}

			for (int i = 0; i < num; i++) {
				printf("addr[%d]\n", i + 1);
				printf("\tname: %s\n", paddr[i]->name);
				printf("\tage: %d\n", paddr[i]->age);

				free(paddr[i]);
			}

			free(paddr);
		}
		else {
			break;
		}
	}
}
```

## 12. 공용체

```C
define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
	char byte;
	struct
	{
		int a : 1;
		int b : 2;
		int c : 2;
		int d : 1;
	}bits;
}uniVar;

void main()
{
	uniVar var;
	memset(&var, 0, sizeof(uniVar));

	var.bits.a = 1;
	printf("var.byte = %d\n", var.byte);

	memset(&var, 0, sizeof(uniVar));
	var.bits.b = 1;
	printf("var.byte = %d\n", var.byte);

	memset(&var, 0, sizeof(uniVar));
	var.bits.c = 1;
	printf("var.byte = %d\n", var.byte);

	memset(&var, 0, sizeof(uniVar));
	var.bits.d = 1;
	printf("var.byte = %d\n", var.byte);
}
```

```
1
2
8
32
```

- 구조체는 멤버들이 각각 공간을 차지 하지만 공용채는 모든 멤버가 공간을 공유한다.
- 공용체의 총 크기는 char크기인 1 byte이다. 이 공용체 1 byte를  a에는 1bit, b와 c에는 2bit, d는 1bit를 할당하였다.(리틀엔디안으로 표 작성) 

| 낮은자릿수 | 1bit | 1bit | 1bit | 1bit | 1bit | 1bit | 1bit | 1bit | 높은수자리 수|
| ---------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |---- |
|            | -    | -    | d    | c    | c    | b    | b    | a    ||

- 1. memset으로 메모리 0으로 초기화

     | -    | -    | d    | c    | c    | b    | b    | a    |
     | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
     | 0    | 0    | 0    | 0    | 0    | 0    | 0    | 0    |

  2. `var.bit.a = 1` 할당

     | -    | -    | d    | c    | c    | b    | b    | a    |
     | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
     | 0    | 0    | 0    | 0    | 0    | 0    | 0    | 1    |

  3. memset으로 메모리 0으로 초기화
	
      | -    | -    | d    | c    | c    | b    | b    | a    |
        | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
        | 0    | 0    | 0    | 0    | 0    | 0    | 0    | 0    |
	
  4. `var.bit.b= 1` 할당
  
      | -    | -    | d    | c    | c    | b    | b    | a    |
        | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
        | 0    | 0    | 0    | 0    | 0    | 0    | 1   | 0    |
  
	5. memset으로 메모리 0으로 초기화
  
      | -    | -    | d    | c    | c    | b    | b    | a    |
        | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
	      | 0    | 0    | 0    | 0    | 0    | 0    | 0    | 0    |
  
  6. `var.bit.b= 1` 할당
  
      | -    | -    | d    | c    | c    | b    | b    | a    |
      | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
      | 0    | 0    | 0    | 0    | 1   | 0    | 0  | 0    |


## 참고사이트

[자료형](https://lovelyoverflow.tistory.com/15)

[[C언어] 출력 형식 총정리](https://reakwon.tistory.com/169)

[c언어 정적변수, 지역변수, 전역변수 비교 (static, local, global)](https://code4human.tistory.com/128)

[배열은 수정 가능한데 포인터는 수정 불가?](https://pang2h.tistory.com/77)

[C언어 코딩 도장](https://dojang.io/mod/page/view.php?id=327)