#include <iostream>
#include <string.h>

using namespace std;

// ���׸� �ٸ� �Ǻ���ġ ����
// �ܵ� ������ �ȵż� �׽�Ʈ�� �ּ�
int cache[1000001];
int solve(int n){
    if(n == 0 || n == 1)
        return cache[n] = 1;                
    int& ret = cache[n];
    if(ret != -1)
        return ret;
    ret = (solve(n-1) + solve(n-2)) % 15746;
    return ret;
}

int main(){
    int n;
    cin >> n;
    memset(cache,-1,sizeof(cache));
    cache[0] = 1;
    cout << solve(n);
    return 0;
}