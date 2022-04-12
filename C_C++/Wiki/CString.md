# CString

## 1. 문자열 검색

#### 1.1 Find

- CString 개체의 문자열 기준, 좌측부터 문자 혹은 문자열을 검색
- int Find(TCHAR ch) const;
- 반환값 : 검색된 위치, 실패시 -1;

```cpp
CStirng strText = L'3.143';

int result = strText.Find(L'.');
printf("%d\\n", result);
```

```cpp
1
```

#### 1.2 ReverseFind 

- CString 개체의 문자열 기준, 우측(역순)에서부터 문자를 검색
- int ReverseFind( TCHAR ch ) const;
- 반환값 : 검색된 위치, 실패 시 -1

```C++
CStirng strText = L'3.143';

int result = strText.ReverseFind (L'.');
printf("%d\\n", result);
```

```
3
```

## 2. 문자열 비교

- operator ==, !=, <, >, <=, >= 도 **대소문자를 구분**하여 CString의 문자열을 비교할 수 있다.

#### 2.1 Compare 

- 대소문자를 구분하여 문자열을 비교(아스키코드 기준)

- int Compare( LPCTSTR lpsz ) const;

- 반환값 

  문자열이 lpsz보다 작을 경우 -1
  문자열이 lpsz와 같을 경우 0
  문자열이 lpsz보다 큰 경우 1

```C++
CString strText1;
strText1 = "ABC";

printf(strText1.Compare("ABC"));
printf(strText1.Compare("abc"));
printf(strText1.Compare("123"));
```

```
0
-1
1
```

#### 2.2 CompareNoCase

- 대소문자를 구분하지 않고 문자열을 비교

- int CompareNoCase( LPCTSTR lpsz ) const;

- 반환값 

  문자열이 lpsz보다 작을 경우 -1
  문자열이 lpsz와 같을 경우 0
  문자열이 lpsz보다 큰 경우 1

```C++
CString strText1;
strText1 = "ABC";

printf(strText1.CompareNoCase("ABC"));
printf(strText1.CompareNoCase("abc"));
```

```
0
0
```

## 3. 문자열 비우기 & 비어있나 확인

#### 3.1 Empty 

- CString 개체의 문자열을 비운다.
- void Empty( );

```c++
CString strText;
strText = "abcd13579";
strText.Empty( );
```

#### 3.2 IsEmpty 

- CString 개체가 갖고 있는 문자열이 비어있는지 확인
- BOOL IsEmpty( ) const;
- 반환값 : 문자열이 비어있으면 TRUE, 비어 있지 않으면 FALSE를 반환

```c++
CString strText;
strText = "abcd13579";

if(IsEmpty(strText)){
    printf("%s", strText);
}
```

---

## 참고사이트 & 출처

[MFC/문자열 함수](https://shaeod.tistory.com/401)

