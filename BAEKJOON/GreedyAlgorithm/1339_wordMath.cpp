#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

int N, sum = 0, num = 9, w[26];
string word[10];
bool compare(const int& a, const int& b){
    return a > b;
}

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> word[i];    
    memset(w,0,sizeof(w));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < word[i].size(); j++)
            w[word[i].at(j) - 'A'] += pow(10, word[i].size() - j - 1);

    sort(w, w + 26, compare);
    for(int i = 0; i < 26; i++){
        if(w == 0) break;
        sum += w[i] * num;
        num--;
    }
    cout << sum;
    return 0;
}