#include <stdio.h>
// 재귀의 활용

/*
함수 : 호출 관계와 호출 순서 이해
재귀함수 -> 호출 관계로만으로도 이해할 수 있어야 함
코드를 통해 호출 관계와 호출 순서까지 파악하는 것 자체가 너무 복잡함.
결론) 너무 복잡하게 들어가지 마라. 관계정도 까지만 파악

*/

/*
* 피보나치 수열
fib(n) = 0 (n = 1일때)
fib(n) = 1 (n = 2일때)
fib(n) = fib(n-1) + fib(n-2) otherwise
문제를 보고 1. 논리를 세우고, 2. 코드를 쓰면 끝!
*/

// 피보나치 수열 코드

int fib(int n) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}