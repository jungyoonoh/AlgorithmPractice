#include <stdio.h>
// C 생각해보기
// 자료형 받을때 %
// 변수 참조시 &
int main(){
    // C
    char c;
    scanf("%c", &c);
    printf("%d", c);
}

#include <iostream>
using namespace std;
int main(){
    // C++
    // char로 입력받고 int로 형변환 후 출력
    char a;
    cin >> a;
    cout << (int) a;
    return 0;
}