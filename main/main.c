#include <stdio.h>
#incldue <string.h>

int main(){
  int a[10] = "Apple";
  int b[10] = "Banana";
  int temp[10];

  strcmp(temp, a);
  strcpy(a, b);
  strcpy(b, temp);

  printf("첫 번째 과일 : %s\n", a);
  printf("두 번째 과일 " %s\n", b);

  retun 0;
}

/*
  int t =5;
  int *k = &t;
  *k = 1; // t=1;
  printf("%d \n", t);

  1. 문자열 "Apple"을 "Banana"로 바꾸기
  2. 변수를 이용한 변경과 포인터를 사용한 변경
  3. 구조체 사용해보기

  목요일까지 과제 제출
  일요일에 세션발표진행

  다음 주는 클래스 직접 만들어보기(생성자, 복사생성자, 접근자)
  포인터, 구조체, 배열, 문자열 -> 클래스에서 계속 이용한
  
*/


/* void swap(char *a, char *b)
{
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
} */


  
