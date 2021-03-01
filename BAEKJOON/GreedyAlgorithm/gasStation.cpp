#include <iostream>
#include <cassert>
using namespace std;

int dist[100000];
int oil[100000];

// 기름 싼곳 찾아서 거기서 다음 싼곳 나올때까지 충전하면 가장 이득
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    // ?? int는 21억이 최대인데 10억 넣으면 오류난다고 백준이 채점함 
    // 앵간하면 큰 자료형으로 때려박는게 이득
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