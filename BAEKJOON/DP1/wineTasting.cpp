#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int n;
int wine[10001];
int cache[10001]; // ��

// ��� ������ �����ѵ� ������ ���� �ݵ�� ���ž� �Ѵٴ� ������ ����
// -> ���� ��쿡�� ������ �ʴ� ��츦 ���
int tasting(){
    for(int i = 1; i < 3; i++)
        i == 1 ? cache[i] = wine[i] : cache[i] = wine[i] + wine[i-1]; // wine 2�� ����
    
    int sav = -1;
    for(int i = 3; i <= n; i++){
        sav = max(cache[i-2] + wine[i], cache[i-3] + wine[i-1] + wine[i]);
        sav = max(cache[i-1], sav); // �ȸ��ô°� �̵��ϼ� �ִ�
        cache[i] = sav;
    }
    
    return cache[n];
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> wine[i];
    memset(cache,0,sizeof(cache));
    cout << tasting() << endl;
    return 0;
}