#include <iostream>

using namespace std;
const long long MOD = 1000000007;

// nCr = n! / r!*(n-r)! = nPr / r!;
// n!�� �����, r! * (n-r)!�� ���ڷ� ��ȯ���־�� �� (modular�� �м��� ����� ����� �ٸ��� ����)
// �丣���� �������� ����
// a = r! * (n-r)! �϶�, a^-1 == a^p-2 (mod p)
// ���� : p�� �Ҽ�, a�� p�� ����� �ƴ� ��

long long solution(long long a, long long b){
    if(b == 0) return 1;
    long long temp = solution(a, b / 2);
    if(b % 2 == 0) return (temp * temp) % MOD;
    if(b % 2 == 1) return (((temp * temp) % MOD) * a) % MOD;
}

long long factorial(int n){
    long long temp = 1;
    for(int i = 1; i <= n; i++){
        temp *= i;
        temp %= MOD;
    }
    return temp;
}

int main(){
    int N, K;
    cin >> N >> K;

    long long nF = factorial(N);
    // a^-1 == a^p-2 (mod p) 
    long long kF = factorial(K);
    long long nmkF = factorial(N-K);
    long long under = solution(kF*nmkF % MOD, MOD - 2);
    cout << nF * under % MOD;
    return 0;
}