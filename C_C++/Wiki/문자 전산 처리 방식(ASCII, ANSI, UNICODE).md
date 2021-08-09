# 문자 전산 처리 방식(ASCII, ANSI, UNICODE)

## 1. ASCII 

- ASCII Table 
  <img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F2704094E52695030217D71" title="ASCII Table"></img>
- **ASCII** (**A**merican **S**tandard **C**ode for **I**nformation **I**nterchange, 미국 정보 교환 표준 부호)로 아스키라고 읽는다.
- 7bit 부호체계로 128개의 부호가 사용횐다. 이는 영문 키보드로 입력할 수 있는 모든 기호들이 할당되어있다.
- 영문 알파벳 대소문자 52개, 숫자 10개, 특수문자 32개, 널 문자 1개로 이루어져있다.
- 1byte를 구성하는 8bit 중 7bit만 사용한 이유는 나머지 1비트는 통신 에러를 검출 하기 위해 사용하기 때문이었다. 하지만 문제점이 있어 더이상 사용하지 않는다.
- 영화 <마션>에서 맷데이먼이 아스키코드를 사용하여 NASA와 통신하는 장면 있다.  <sup>[1](#footnote_1)</sup>
- C언어 예시
```C
//아스키코드표를 65는 문자 A를 가르키고, 97은 문자 a를 가르킨다. 
printf("문자: %c \n", 65);
printf("문자: %c \n", 97);
       
printf("ASCII decimal: %d\n", 'A');
printf("ASCII decimal: %d\n", 'a');   
```

```
문자 : A
문자 : a

ASCII decimal : 65
ASCII decimal : 97
```

## 2. ANSI 

- ASCII에서 1bit를 통신에러 검출용이 아닌 영어가 아닌 다른언어를 표현하기 위해 사용되었다. 
- ANSI는 8bit로 구성되어있으면 256개의 문자를 표현할 수 있다. 

- ANSI의 앞 7bit는 ASCII와 동일하고, 뒤에 1bit를 이용하여 다른 언어의 문자를 표현한다.
- 그러나 256개로는 여전히 많은 언어를 표현하지 못했다.

## 3. UNICODE

전 세계의 모든 문자를 다루도록 설계된 표준 문자 전산 처리 방식

#### 3.1 유니코드 역사

- 초기 유니코드는 2byte로 65,536개의 문자를 표현할 수 있었다.

  65,536개에 온 세상 문자를 모두 담을 수 있을거라고 생각했지만 쓰지 않는 고어(古語), 아프리카 토속어 등등 모든 문자를 담으려다 하다보니 이마저도 부족했다. 이를 해결하기 위해 **유니코드 3.0**부터 보충언어판(Supplementary Planes)를 정의했다.  

  보충언어판에서는 0x0000부터 0xFFFF까지 문자를 배정해놓은 세트를 총 17개로 늘리게 된다. 

  이 세트들을 유니코드에서는 “평면”이라고 부르고, 앞에서부터 0번 ~ 16번 까지 번호를 붙여놓았습니다. ( 현재 사용되고 있는 평면은 0 ~ 2번과 14 ~ 16번의 6개 평면입니다. ) 이 평면중에서 현대에서 쓰이는 문자들을 모두 0번 평면에 몰아넣었는데 이 평면을 기본 다국어 평면(BMP, Basic multilingual plane)라고 한다.

- 유니코드를 표시하는 방법 : **U+**

  유니코드에서는 모든 평면이 0x0000부터 0xFFFF의 값을 가지고 있기 때문에 문자끼리 겹치는 현상이 발생하여 U+ 라는 기호에 평면 숫자를 붙이는 방식을 사용하게 되었다. ( 단, 0번 평면의 경우는 숫자를 붙이는 것을 생략)

  - U+B000 : 뀀
- U+1B000 : ![img](https://blog.kakaocdn.net/dn/DqMr7/btqv7QN9l2T/aLX0rN1qZGAYZlkvSBkvRk/img.png)

#### 3.2 유니코드 인코딩 종류

##### 3.2.1 UCS-2

- UCS-2 방식은 유니코드의 모든 평면의 문자를 모두 인코딩 하지 않고, 0번 기본 다국어 평면 (BMP)만을 인코딩하는 방식
- 0번 평면의 0x0000~0xFFFF까지의 문자를 그대로 고정 2바이트 형식으로 표현
- 2바이트를 사용하여 엔디안 문제가 발생한다. 이를 해결하기 위해서 2바이트인 BOM(Byte Order Mark)을 유니코드 파일이 시작되는 첫 부분에 명시해서 문자열이 어떤 엔디안 방식을 사용하는지 명시하도록 하였다.
- BOM종류

<img src = "https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FXBqFX%2Fbtqv9sk4P2R%2FkNkQpgFxk69KokOVukMXz1%2Fimg.png" width="600" height="200px"  title = "BOM Table" ></img>

##### 3.2.2 UTF-16

- UTF-16은 기본 다국어 평면에 속하는 문자들을 표현할 때는 UCS-2와 같지만, 2바이트를 넘어서는 문자는 4바이트를 표현하도록 하는 가변길이 인코딩 기법

- 표현방식

  2바이트 : 기본 다국어 평면(BMP)

  4바이트 : 2바이트를 넘어선 모든 유니코드 문자

- UTF-16은 ASCII와 호완되지 않는다. 또한 최소 2바이트를 사용해 문자를 표현하기 때문에 엔디안문제가 발생할 수 있어 리틀엔디안, 빅 엔디안에 따라 값이 바뀔 수 있어 BOM을 붙이도록 되어있다.

##### 3.2.3 UTF-8

- UTF-8은 가장 많이 사용되는 가변 길이 인코딩입니다. 문자에 따라서 1바이트 ~4바이트로 인코딩 될 수 있으며, UTF-16과 다르게 ACSII와 하위 호환성을 가진다.

- 표현방식

  1바이트 : ASCII 

  2바이트 : 아랍, 히브리, 대부분의 유럽계

  3바이트 : 기본 다국어 평면(BMP)

  4바이트 : 모든 유니코드 문자

  <img src = "https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbL8INu%2Fbtqv9tjW9dx%2Fa7rVYqMjL4LqMKEwDXZSFK%2Fimg.png" width = "600px" title="UTF8 Table"></img>

- UTF-8은 장점
  - 단일 인코딩방식으로 엔디안 문제가 발생하지 않아 BOM이 필요없다.
  - ASCII와 호환이 되어 기존 ASCII로 구축되어있던 오래된 인터넷문서를 변화 처리없이 사용가능
  - 파싱에 예외모드 확장 문자 처리가 필요없다.

#### 3.3 유니코드와 한글

- 유니코드 BMP 한글 코드 범위는 {AC00-D7AF}이다. <sup>[2](#footnote_2)</sup>

<img src = "https://jinios.github.io/assets/img/post_img/2018-06-23-unicode-koean.png" width = "600"
  title = "unicode korea language table"></img>



## 참고사이트

[아스키코드](https://whatisthenext.tistory.com/103)

[아스키 코드, 유니코드 그리고 UTF-8, UTF-16](https://dingue.tistory.com/16)

[한글 인코딩의 이해(유니코드) 완전 기초!](https://jinios.github.io/study/2018/06/23/unicode_background_korean/)

## 주석

<a name="footnote_1">1</a>: [ 마션 장면 유튜브](https://www.youtube.com/watch?v=k-GH3mbvUro)

<a name="footnote_2">2 </a>: [유니코드 한글표 U+A0000](https://ko.wikipedia.org/wiki/%EC%9C%A0%EB%8B%88%EC%BD%94%EB%93%9C_A000~AFFF)

