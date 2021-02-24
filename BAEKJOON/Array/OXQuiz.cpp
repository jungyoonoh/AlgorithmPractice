#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    string* quiz;
    quiz = new string[n];
    for(int i = 0; i < n; i++){
        cin >> quiz[i];
        int sum = 0, score = 0;
        for(int j = 0; j < quiz[i].size(); j++){
            if(quiz[i].at(j) != 'X')
                sum += ++score;
            else score = 0;
        }
        cout << sum << '\n';
    }

    return 0;
}