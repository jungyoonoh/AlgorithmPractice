#include <iostream>
#include <stack>
#define SIZE 20
using namespace std;

int n, arr[100001];
char ans[SIZE];
stack<int> s;
int main(){  
    cin.tie(NULL); cin.sync_with_stdio(false);  
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int seq = 1, idx = 0, markIdx = 0;
    while(1){
        if(!s.empty() && s.top() == arr[idx]){
            s.pop();
            idx++;
            ans[markIdx++] = '-';
        }else {
            if(seq > n) {cout << "NO"; break;}
            s.push(seq);
            seq++;
            ans[markIdx++] = '+';
        }
        if(idx == n && seq == n + 1){
            for(int i = 0; i < markIdx; i++)
                cout << ans[i] << '\n';            
            break;
        }
    }
    
    return 0;
}