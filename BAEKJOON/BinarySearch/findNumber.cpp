#include <iostream>
#include <algorithm>
using namespace std;

int N, M, A[100000];
bool flag = false;
void findNum(int start, int end, int num){
    if(start > end || flag) return;
    int mid = (start + end) / 2;
    if(A[mid] == num) {flag = true; return;}
    else if(A[mid] > num) findNum(start, mid - 1, num);
    else findNum(mid + 1, end, num);
}

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    cin >> M;
    int val;
    sort(A, A+N);
    for(int i = 0; i < M; i++){
        cin >> val;
        flag = false;
        // N 일때도 성공함... 데이터 추가가 필요해보임
        findNum(0,N - 1,val);
        flag ? cout << 1 << '\n' : cout << 0 << '\n';
    }

    return 0; 
}