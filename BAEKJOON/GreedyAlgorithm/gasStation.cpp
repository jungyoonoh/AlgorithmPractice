#include <iostream>
#include <cassert>
using namespace std;

int dist[100000];
int oil[100000];

// �⸧ �Ѱ� ã�Ƽ� �ű⼭ ���� �Ѱ� ���ö����� �����ϸ� ���� �̵�
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    // �����÷ο찡 ���� ���� == ������ �� ����
    // long long = int x int (x) -> overflow
    // long long = long long x int (o)
    // long long = long long x long long (o)
    long long n, min = 1000000001; 
    cin >> n;
    long long minimumCost = 0;   

    for(int i = 0; i < n - 1; i++)
        cin >> dist[i];
    for(int i = 0; i < n; i++){
        cin >> oil[i];
        if (oil[i] < min)
            min = oil[i];
        minimumCost += min * dist[i];
    }
    cout << minimumCost;
    return 0;
}