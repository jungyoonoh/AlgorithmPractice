#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int N, val;
vector<int> LIS;

int cache[1001];
int A[1001];
int ans = 0;


// int main(){
//     cin >> N;
//     for(int i = 1; i <= N; i++)
//         cin >> A[i];    
//     for(int i = 1; i <= N; i++){
//         int here = 0;
//         for(int j = 1; j < i; j++){
//             if(A[j] < A[i])
//                 here = max(here, cache[j]); // 갱신            
//         }
//         cache[i] = here + 1; // 아니면 무조건 1 
//         ans = max(ans, cache[i]); // 현재 vs 다른곳에서 구했던 최댓값
//     }
//     cout << ans << endl;
//     return 0;
// }

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> val;
        if(LIS.empty() || LIS.back() < val)
            LIS.push_back(val);
        else {
            vector<int>::iterator it = lower_bound(LIS.begin(), LIS.end(), val);
            *it = val; // 갱신
        }
    }
    cout << LIS.size() << endl;
    return 0;
}