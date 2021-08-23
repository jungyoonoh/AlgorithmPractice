#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int tc,N,fNL,WCL;
string wildcard,FN;
vector <string> fileName;
int dp[101][101];
int checkWildCard(int i, int j); // WC idx & FN idx
void init();
int checkWildCard(int i, int j) {
    
	if (i >= WCL) // 기저
		return j == fNL;

	int& r = dp[i][j];
	if (r != -1)  // 캐싱
		return r;

	if (wildcard[i] == '*') 
		for (int k = j; k <= fNL; k++)
			if (checkWildCard(i + 1, k) == 1) // WC의 다음 idx와 FN의 다음 idx가 같은게 나올때까지 *로 대응
				return r = true;

	if (wildcard[i] == FN[j] || wildcard[i] == '?') // 같음 or 하나 대응
		return r = checkWildCard(i + 1, j + 1);

	return r = false;
}
void init() {
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			dp[i][j] = -1;
}
int main() {
	cin >> tc;
	while (tc--) {
		cin >> wildcard;
		cin >> N;
		WCL = wildcard.size();
		fileName.clear();
		for (int i = 0; i < N; i++) {
			cin >> FN;
			init();
			fNL = FN.size();
			if (checkWildCard(0,0) == 1)
				fileName.push_back(FN);
		}
		sort(fileName.begin(), fileName.end());
		for (int i = 0; i < fileName.size(); i++)
			cout << fileName[i] << endl;
	}
	return 0;
}