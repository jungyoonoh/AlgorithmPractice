#include <iostream>

using namespace std;

string input;

string solve(string input){
    string output = input;
    int idx = 0;
    for(int i = 0; i < input.size(); i+=2)
        output[idx++] = input[i];

    for(int i = 1; i < input.size(); i+=2)
        output[idx++] = input[i];

    return output;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> input;
        cout << solve(input) << endl;
    }
    return 0;
}