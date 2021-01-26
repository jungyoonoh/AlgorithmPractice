#include <iostream>
#include <math.h>
#include <algorithm>
#define MAX 200000000
// 10R...
// A to B �� minimum�� ���Ҷ� ����� ������ INF
// INT_MAX�� �ʱⰪ���� ���
// �����÷ο찡 ���� -21������ ���� �� �ִ� ��츦 ĳġ���� ���ߴ�.. 
using namespace std;

int cache[10005];
string pi;

// ���� ������ ���̵� Ž��
int getLV(int begin, int end){
    string splitstr = pi.substr(begin, end - begin + 1);
    string strLv1 = "";
    for(int i = 0; i < splitstr.size(); i++)
        strLv1 += splitstr[0];
    if(splitstr == strLv1)
        return 1;

    // ����
    bool isSequence = true;
    for(int i = 0; i < splitstr.size() - 1; i++)
        if(splitstr[i+1] - splitstr[i] != splitstr[1] - splitstr[0])
            isSequence = false;


    if(isSequence){
        if(abs(splitstr[1] - splitstr[0]) == 1) return 2; // ����1
        else return 5; // �� ��
    }        
    
    bool isCross = true;
    // ����
    for(int i = 0; i < splitstr.size(); i++)
        if(splitstr[i] != splitstr[i%2])
            isCross = false;
    
    if(isCross) return 4;
    return 10;
}

int solve(int idx){
    // �������
    if(pi.size() == idx)
        return 0;
    
    // ���� ���� o
    int& ret = cache[idx];
    if(ret != -1) return ret;

    ret = MAX;
    // 3 ~ 5���ڷ� ©����
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