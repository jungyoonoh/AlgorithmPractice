#include <iostream>
#include <math.h>
#include <algorithm>
#define MAX 200000000
// 10R...
// A to B 의 minimum을 구할때 행렬의 기저는 INF
// INT_MAX를 초기값으로 사용
// 오버플로우가 나서 -21억으로 빠질 수 있는 경우를 캐치하지 못했다.. 
using namespace std;

int cache[10005];
string pi;

// 일정 구간의 난이도 탐색
int getLV(int begin, int end){
    string splitstr = pi.substr(begin, end - begin + 1);
    string strLv1 = "";
    for(int i = 0; i < splitstr.size(); i++)
        strLv1 += splitstr[0];
    if(splitstr == strLv1)
        return 1;

    // 등차
    bool isSequence = true;
    for(int i = 0; i < splitstr.size() - 1; i++)
        if(splitstr[i+1] - splitstr[i] != splitstr[1] - splitstr[0])
            isSequence = false;


    if(isSequence){
        if(abs(splitstr[1] - splitstr[0]) == 1) return 2; // 공차1
        else return 5; // 그 외
    }        
    
    bool isCross = true;
    // 교차
    for(int i = 0; i < splitstr.size(); i++)
        if(splitstr[i] != splitstr[i%2])
            isCross = false;
    
    if(isCross) return 4;
    return 10;
}

int solve(int idx){
    // 기저사례
    if(pi.size() == idx)
        return 0;
    
    // 사전 참조 o
    int& ret = cache[idx];
    if(ret != -1) return ret;

    ret = MAX;
    // 3 ~ 5글자로 짤리기
    for(int i = 3; i <= 5; i++)
        if(idx + i <= pi.size())
            ret = min(ret, solve(idx + i) + getLV(idx, idx + i - 1));
    
    return ret;
}

void init(){
    for(int i = 0; i < 10005; i++)
        cache[i] = -1;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> pi;
        init();
        cout << solve(0) << endl;
    }
    return 0;
}