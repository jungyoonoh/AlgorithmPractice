#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

// N�� �������� M
// 245�� �������� 256
// 245�� 256�� ������
// �����ڴ� ���ų� ������
int digitGen[1000001];
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        int t = i;
        digitGen[i] = t; 
        while(t > 0){
            digitGen[i] += t % 10;
            t /= 10;            
        }
    }
    for(int i = 1; i <= N; i++){
        if(digitGen[i] == N){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}