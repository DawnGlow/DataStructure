#include <stdio.h>
// 재귀함수

void Recursive(void) {
    printf("Recursive call!\n");
    Recursive();
}
/*
* 재귀함수 작동이 가능한 이유
cpu 작동을 위한 명령문이 컴파일 시에 만들어짐
명령문 원본을 이동, 복사시켜 실행하기 때문에 재귀함수가 가능
원본 함수가 있는데 함수기 실행될 때 마다 복사본 실행
실행이 끝나면(return) 자기를 실행한 영역으로 이동
A->B->C->D(종료)->C->B->A

* 재귀함수에는 탈출 조건이 존재한다
void Recursive(int num) {
    if (num <= 0)
        return;// 탈출
    printf("Recursive call %d\n", num);
    Recursive(num-1);
}

* 재귀함수의 디자인 사례
- 팩토리얼
n! == n * (n-1)!
f(n) == n * f(n-1) (n>=1) //  else return n * Factorial(n-l);
f(n) == 1 (n=0) // if(n==0) return 1;
--> 수식과 유사한 형태
*/

// Factorial 함수 코드
int Factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * Factorial(n - 1);
    }
}
