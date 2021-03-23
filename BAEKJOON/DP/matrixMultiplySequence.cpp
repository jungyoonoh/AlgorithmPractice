#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 501
#define MAX 2147483647
using namespace std;

vector <pair<int, int>> a;
int n,r,c;
int cache[SIZE][SIZE];

int sequence(int left, int right){
    if(left == right) return 0;
    int& ret = cache[left][right];
    if(ret != MAX) return ret;
    if(left + 1 == right) return ret = a[left].first * a[left].second * a[right].second;

    for(int i = left; i < right; i++)
        ret = min(ret, sequence(left, i) + sequence(i+1, right) + a[left].first * a[i].second * a[right].second);

    return ret;
}

void init(){
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            cache[i][j] = MAX;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> r >> c;
        pair<int,int> temp = make_pair(r,c);
        a.push_back(temp);
    }
    init();
    cout << sequence(0,n-1);
    
    return 0;
}