#include <iostream> 

using namespace std;

int cache[101][10]; // �ڸ��� �� ��ܼ�
int N;
const int mod = 1000000000;
int solve(){
    for(int i = 0; i < 10; i++) // 1�ڸ� ���
        cache[1][i] = 1;
    
    for(int i = 2; i <= N; i++){
        for(int j = 0; j < 10; j++){ // ���� ���� ��
            if(j == 0) cache[i][j] = cache[i-1][j+1] % mod; 
            else if(j == 9) cache[i][j] = cache[i-1][j-1] % mod; 
            else cache[i][j] = (cache[i-1][j-1] + cache[i-1][j+1]) % mod;
        }
    }
    int sum = 0;
    // �տ� ���ڸ� �ٿ��� ��������
    for(int i = 1; i < 10; i++)
        sum = (sum + cache[N][i]) % mod;
    return sum;
}

int main(){
    cin >> N;
    cout << solve() << endl;
    return 0;    
}