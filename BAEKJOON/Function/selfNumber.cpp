#include <iostream>
#include <string.h>

using namespace std;

int isSelf[10001]; // 1 ~ 10000����

void d(int n){
    // n�� n�� �� �ڸ����� ���ϴ� �Լ�
    if(n > 10000) return;
    int sav = n, sum = 0;
    while(sav > 0){
        sum += sav % 10;
        sav /= 10;
    }
    isSelf[sum+n] = 0;
    d(sum + n);
}


int main(){
    memset(isSelf,-1,sizeof(isSelf));
    for(int i = 1; i <= 10000; i++){
        if(isSelf[i] != 0)
            d(i);
    }

    for(int i = 1; i <= 10000; i++)
        if(isSelf[i] == -1) cout << i << '\n';
    
    return 0;
}