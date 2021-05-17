#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int L,C;
char V[16];
string str;

bool check(){
    int a = 0, b = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') a++;
        else b++;
    }
    if(a >= 1 && b >= 2) return true;
    return false;
}

void solve(int idx, int cnt){
    if(cnt == L && check())
        cout << str << endl;

    for(int i = idx; i < C; i++){
        str.push_back(V[i]);
        solve(i+1, cnt+1);
        str.pop_back();
    }    
}


int main(){
    cin >> L >> C;
    for(int i = 0; i < C; i++)
        cin >> V[i];
    sort(V, V+C);
    solve(0,0);
    return 0;
}