#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int N, M, S = 0, minimum;
bool cant[10];
int ans[6];
int findNum(int n){
    if(n == 0){
        if(cant[0]) return 0;
        else return 1;
    }
    int len = 0;
    while(n > 0){
        if(cant[n % 10]) return 0; // 눌러서 못만드는 숫자인 경우
        n /= 10;
        len++;
    }
    return len; // 만들 수 있을 경우 자릿수 반환

    // 아래와 같이 중복조합으로 접근하면 안됨, 길이가 다른 정답도 가능함
    // if(len == S){
    //     int sum = 0;
    //     for(int i = len - 1; i >= 0; i--)
    //         sum += ans[i] * pow(10, len - 1 - i);
    //     minimum = min(minimum, abs(N - sum) + len);     
    // }
    // for(int i = 0; i <= 9; i++){
    //     if(len == 0 && i == 0 && S != 1) continue;
    //     else{
    //         if(cant[i] != -1){
    //             ans[len] = i;
    //             findNum(len+1);
    //         }
    //     }
    // }
    // return;
}

int main(){
    int temp;
    cin >> N >> M;
    memset(cant,0,sizeof(cant));
    for(int i = 0; i < M; i++){
        cin >> temp;
        cant[temp] = true;
    }
    minimum = abs(N - 100);
    if(minimum == 0) {cout << 0; return 0;}
    for(int i = 0; i <= 1000000; i++){
        temp = i;
        int length = findNum(temp);
        if(length > 0){
            int press = abs(temp - N);
            minimum = min(minimum, press + length);
        }
    }

    cout << minimum;

    return 0;
}