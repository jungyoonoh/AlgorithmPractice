#include <iostream>

using namespace std;
int idx, num = 1;
string input;

void solve(){
    char output[81] = {0,};
    int j = 0;
    for(int i = 0; i < input.size(); i++){
        if(i != idx - 1)
            output[j++] = input[i];
    }
    cout << num++ << " " << output << endl;
}

int main(){
    int tc;
    cin >> tc;    
    while(tc--){
        cin >> idx;
        cin >> input;
        solve();
    }
    return 0;
}