#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <deque>
using namespace std;

deque<int> dq;
string ans = "", maxVal = "", minVal = "";
char arr[10];
bool isCheck[10];
int k;

void solve(int cnt){
    if(cnt > k) {
        ans = "";
        for(int i = 0; i < dq.size(); i++)
            ans += to_string(dq[i]);                    
        maxVal = maxVal <= ans ? ans : maxVal;
        minVal = minVal >= ans ? ans : minVal;
        return;
    }
    
    for(int i = 0; i <= 9; i++){
        if(!isCheck[i]){
            if(cnt != 0 && arr[cnt - 1] == '>' && dq.back() > i)
                dq.push_back(i);    
            else if(cnt != 0 && arr[cnt - 1] == '<' && dq.back() < i)
                dq.push_back(i);    
            else if(cnt == 0)
                dq.push_back(i);
            else continue;
            isCheck[i] = true;
            solve(cnt+1);
            dq.pop_back();
            isCheck[i] = false;
            
        }
    }

}

int main(){
    cin >> k;
    for(int i = 0; i < k; i++) cin >> arr[i];
    for(int i = 0; i <= k; i++){
        maxVal += '0';
        minVal += '9';
    }
    solve(0);
    
    cout << maxVal << '\n' << minVal;
    return 0;
}