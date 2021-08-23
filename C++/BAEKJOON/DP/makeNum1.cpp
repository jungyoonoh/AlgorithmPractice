#include <iostream> 
#include <algorithm>

using namespace std;
int N;
int cache[10000001] = {0,};
int solve(){
    cache[1] = 0;
    // bottom up
    for(int i = 2; i <= N; i++){
        cache[i] = cache[i-1] + 1; // -1 
        if(i % 2 == 0) cache[i] = min(cache[i], cache[i/2] + 1); // /2 
        if(i % 3 == 0) cache[i] = min(cache[i], cache[i/3] + 1); // /3 
    }

    return cache[N];
}

int main(){
    cin >> N;
    cout << solve() << endl;
    return 0;
}