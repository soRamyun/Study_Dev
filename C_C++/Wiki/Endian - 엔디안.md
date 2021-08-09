# Endian - 엔디안

## 1. Byte Order - 바이트오더

- 언어를 왼쪽에서 부터 읽는 국가, 오른쪽에서 부터 읽는 국가가 다르듯 컴퓨터에서도 데이터 저장방식이 다르다. 

| --읽는 방식--->| 안   | 녕   | 하   | 세   | 요   |
| ---- | ---- | ---- | ---- | ---- | ---- |
| <--읽는 방식---| 요   | 세   | 하   | 녕   | 안   |

- 컴퓨터에서는 저장되는 데이터의 최소단위가 1**Byte**이기 때문에 데이터를 낮은 주소에서 높은 주소로 저장하느냐, 높은 주소에서 낮은주소로 저장하는지에 따라 순서의 차이가 있다**(Order)**. 따라서 **BYTE+Order = 바이트 오더**라고한다.

| 주소   | 0x10 | 0x11 | 0x12 | 0x13 | 0x14 |
| ------ | ---- | ---- | ---- | ---- | ---- |
| 데이터 | h    | e    | l    | l    | o    |

- byte order는 크게 빅엔디안, 리틀엔디안 방식이 있다.
- bit단위에서는 저장순서의 차이가 없고 왼쪽에서 오른쪽으로 읽는다. 

## 2. Endian

엔디언이라는 단어는 <걸리버 여행기>에 나오는 소인국 릴리퍼트이야기에서 달걀을 깰 때 뭉툭한 끝(big-end)를 먼저 깨는 사람들(빅 엔디언)과 뽀족한 끝(little-end)를 먼저 깨는 사람들(리틀 엔디언) 사이에 격론이 벌어진 데서 따온 것이다.

#### 2.1 Big Endian - 빅 엔디안 

- 왼쪽(낮은 주소)에서 오른쪽(높은 주소)로 저장하는 방식
- 0x12345678

| 1byte | 1byte | 1byte | 1byte |
| -------- | ------ | ------- | -------- |
| 12       | 34     | 56      | 78       |

낮은주소																																																												   

#### 2.2 Little Endian - 리틀 엔디안 

- 오른쪽(높은 주소)에서 왼쪽(낮은 주소)로 저장하는 방식
- 0x12345678

| 1byte | 1byte | 1byte | 1byte |
| ----- | ----- | ----- | ----- |
| 78    | 56    | 34    | 12    |

낮은주소																																																										

- bit는 저장순서가 왼쪽 -> 오른쪽이기 때문에 87654321로 저장되지 않는다. 

#### 2.3 Big Endian VS Little Endian

<img src = "https://blog.kakaocdn.net/dn/bKlfXd/btqCBwHKpmr/iUcwN47HTguBfdf9iwtpDK/img.png" width = "400"></img>

- Big Endian

  - 숫자 비교 - 빅엔디안은 큰 자리수가 메모리 맨 앞에 위치하기 때문에 값을 비교하기 좋아 Little Endian보다 속도가 빠르다.
  - 디버깅 확인 - 사람이 읽는 순서와 동일하게 메모리에 저장되기 때문에 디버그가 하기가 좋다.

- Little Endian 

  - 수학 연산 - 가장 낮은 자리 수에 있는 숫자를 계산해 보고 자리 올림수가 있는 지 없는지 판단하고 자리 올림수와 다음 숫자를 계산하기 때문에 Big Endian보다 빠르다.
  
  <img src = "https://blog.kakaocdn.net/dn/cFLsYh/btqCGQzgcBJ/LfV6jInCMeDQ2THzMx4vwK/img.png" width = "700"></img>
  
  <img src = "https://blog.kakaocdn.net/dn/JAvAs/btqCEPuh7HG/zBcKelJj1ANuAWeJV4SGEk/img.png" width = "700"></img>
  
  - 타입형변환 

    <img src = "https://blog.kakaocdn.net/dn/dCD23e/btqCAPWBOxk/YPdgCy0j4mkJh2MOaA3sgk/img.png" width = "300"></img>

- CPU에 의한 Endian 방식

<img src = "https://blog.kakaocdn.net/dn/lPTAK/btqCy3NiZ0a/EFkNmzVpNqonIX1SEkMPy0/img.png"></img>

## 참고자료

[[Byte Order 바이트오터] 빅엔디안(Big Endian)과 리틀엔디안(little endian) - 1편](https://jhnyang.tistory.com/172)

[[endian 2탄] 리틀엔디안 vs 빅엔디안, 각 엔디안방식의 장단점, NBO(network byte order), cpu별 엔디안 차이.](https://jhnyang.tistory.com/226)



