#include <iostream>
#include <string.h>
using namespace std;

// 0�̸� �� �� ����, 1�̸� �� �� ����
int ans = 0, N, chess[15][15];

// ���� ���ʿ�x, �������� �ݵ�� ���� �̵��ϹǷ� x
// -> ���� ���� ĭ �������� �Ʒ��� ������ Ȯ��
void putIt(int y, int x, int value){
    for(int i = 1; y+i < N; i++){
        chess[y+i][x] += value;
        if(x - i >= 0) chess[y+i][x-i] += value;
        if(x + i < N) chess[y+i][x+i] += value;
    }
}

// �����ٷ� �̵�
void doIt(int y){
    if(y == N) {
        ans++;
        return;
    }
    for(int x = 0; x < N; x++){
        if(chess[y][x] == -1){
            putIt(y,x,1);
            doIt(y+1);
            putIt(y,x,-1);
        }
    }

}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> N;
    memset(chess,-1,sizeof(chess));
    doIt(0);
    cout << ans;
    return 0;
}