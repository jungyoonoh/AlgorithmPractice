#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

vector<int> card;
int N, M, J = -1;
// ��ü ����, ���� ǥ��, ������ �̾ƾ� �� ����, ���� ǥ���� ���� ����, ���� iterator
void Combination(vector<int> arr, vector<int> comb, int r, int index, int depth){
    if (r == 0) {
        int sum = 0;
        for(int i = 0; i < comb.size(); i++)
            sum += comb[i];
        if(sum <= M) J = max(J,sum);
    }
    else if (depth == arr.size())  // depth == n
        return;
    else {
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1); // ���� depth�� ���� �̱�
        Combination(arr, comb, r, index, depth + 1); // ���� depth�� ���� �Ȼ̱�
    }
}

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> N >> M;
    int r = 3,a;
    vector<int> comb(r);
    for(int i = 0; i < N; i++){
        cin >> a;
        card.push_back(a);
    }
    
    Combination(card,comb,r,0,0);
    cout << J;
    return 0;
}