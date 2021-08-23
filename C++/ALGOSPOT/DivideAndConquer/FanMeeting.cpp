#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

string member; // F, M : 0, 1 
string fan;

vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			c[i + j] += (a[i] * b[j]);
		}
	}
	return c;
}
void addTo(vector<int>& a, const vector<int> b, int k)
{
	int length = b.size();
	a.resize(max(a.size(), b.size() + k));
	for (int i = 0; i < length; i++)
		a[i + k] += b[i];
}
void subFrom(vector<int>& a, const vector<int>& b)
{
	int length = b.size();
	a.resize(max(a.size(), b.size()) + 1);
	for (int i = 0; i < length; i++)
		a[i] -= b[i];
}
vector<int> karatsuba(const vector<int> &a, const vector<int> &b)
{
	int an = a.size(), bn = b.size();
	if (an < bn) return karatsuba(b, a);
	if (an == 0 || bn == 0) return vector<int>();
	if (an <= 50) return multiply(a, b);
	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}

long long solve(){
    int memberNum = member.size(), fanNum = fan.size();
    vector<int> members(memberNum), fans(fanNum);
    long long totalHug = 0; // ¸â¹ö ÀüºÎ°¡ Æ÷¿Ë == ³²³²ÀÌ ÇÑ½Öµµ x
    for(int i = 0; i < memberNum; i++)
        members[i] = member[i] == 'F' ? 0 : 1;

    for(int i = 0; i < fanNum; i++)
        fans[i] = fan[fanNum - i - 1] == 'F' ? 0 : 1;

    vector<int> sum = karatsuba(members,fans);
    for(int i = memberNum - 1; i < fanNum; i++){
        if(sum[i] == 0)
            totalHug++;
    }
    
    return totalHug;
}

int main(){
	fastio;
    int TC;
    cin >> TC;
    while(TC--){
        cin >> member >> fan;
        cout << solve() << endl;
    }
    return 0;
}