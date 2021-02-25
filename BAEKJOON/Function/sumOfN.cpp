#include <iostream>
#include <vector>
using namespace std;

long long sum(std::vector<int> &a){
    long long ans = 0;
    for(int i = 0; i < a.size(); i++)
        ans += a[i];
    return ans;
}

int main(){
    // 위의 sum 함수만 구현해서 제출하는 문제
    return 0;
}