#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#define MAX 2147483647
#define SIZE 1001
using namespace std;
string A,B;
int dp[SIZE][SIZE];
int main(){
    cin >> A >> B;

    for(int i = 0; i <= A.size(); i++)
        for(int j = 0; j <= B.size(); j++)
            dp[i][j] = MAX;

    for(int i = 0; i <= A.size(); i++)
        dp[i][0] = i;
    for(int i = 0; i <= B.size(); i++)
        dp[0][i] = i;

    for(int i = 1; i <= A.size(); i++){
        for(int j = 1; j <= B.size(); j++){
            if(A.at(i-1) == B.at(j-1)) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
        }
    }

    cout << dp[A.size()][B.size()];

    return 0;
}