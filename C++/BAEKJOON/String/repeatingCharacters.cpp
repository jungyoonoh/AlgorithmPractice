#include <iostream>
#include <string>

using namespace std;

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    int N,M;
    string s;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> M; cin >> s;
        for(int j = 0; j < s.size(); j++)
            for(int k = 0; k < M; k++)
                cout << s.at(j);
        cout << '\n';         
    }
    return 0;
}