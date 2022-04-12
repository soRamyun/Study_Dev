# 메모리 구조(Memory Structure)

## 1. 메모리 구조

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbeCUTJ%2FbtqURvZeZOL%2FqljL316sxeGux63nXoXPIk%2Fimg.png" width = "300px" title="Data structure"></img>

#### 1. Text

- 코드영역으로 코드를 실행하기 위해 저장되어 있는 영역이다. 한마디로 명령문이 저장되는 것인데, 제어문, 함수, 상수들이 저장된다. 

#### 2. Data

- 전역변수, 정적변수 등이 저장되는 공간이다. 프로그램이 종료될 때까지 메모리에 남아있는 변수라는 특징이 있다.
- 초기화된 변수영역(initialized data segment)와 초기화 되지 않은 변수영역(uninitialized data segement)로 나눠진다. 그 중 초기화 되지 않은 변수 영역은 BSS(Block Started by Symbol)이라고도 한다.

#### 3. Heap

- 동적할당 변수들이 저장되는 동적할당 영역이다. 
- 낮은 주소에서 높은 주소로 할당된다. 

#### 4. Stack

- 함수를 호출할 때 지역변수, 매개변수들이 저장되는 공간이다. 메인(main)함수 안에서의 변수도 포함된다.
- 함수가 호출되면 메모리에 할당하고 함수가 종료되면 메모리에서 해제된다. 
- 높은 주소에서 낮은 주소로 메모리에 할당된다.

## 2. 소스코드

``` C
#include <stdio.h>

const int constval = 30;							//(1)

int uninitial; 										//(2)
int initial = 30;									//(3)
static int staticval = 70;							//(4)

int function(){										//(5)
    int functionval = 10;							//(5)
    return 20;										//(5)
}													//(5)

int main(void)
{
    int localval1 = 30;								//(6)
    int localval2 = 20;								//(7)	
    
    char *arr = malloc(sizeof(char) * 10);			//(8)
    
    return 0;
}
```

- (1) `const int constval = 30`은 __상수__이므로 __Text__영역에 저장된다.
- (2) `int uninitial ` 초기화 되지 않은 **전역변수**, (3) `int initial = 30` 초기화 된 **전역변수** , (4) `static int staticval = 70` **정적변수**는 **Data**영역에 저장된다. 다만 초기화 된 변수들이 더 낮은 주소에 위치하고 모두 메모리에 올려지면 그 다음으로 초기화가 안된 변수들이 할당된다.
- (5) 함수 `int function()`는 **Text**영역에 저장된다. 함수 내부 변수 `int functionval = 10`는 함수가 호출함과 동시에 Stack영역에 할당되고, 함수가 종료되면 해제된다.
- (6) `int localval1 = 30`, (7) `int localval2 = 20` 두개는 메인함수의 **지역변수**이므로 **Stack**영역에 저장된다.
- (7) `char *arr = malloc(sizeof(char) * 10)` **동적할당**은 **Heap**영역에 저장된다. 

## 참고사이트

[Stranger's Lab 메모리구조[Memory Structure]](https://st-lab.tistory.com/198?category=872072)

