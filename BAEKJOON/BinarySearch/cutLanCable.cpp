#include <iostream>
#include <algorithm>

using namespace std;

long long K, N, lan[10001], canCut = 0;
bool check(long long value){
    long long lanNum = 0;
    for(int i = 0; i < K; i++)
        lanNum += (lan[i] / value);
    
    if(lanNum >= N) return true; // 딱맞다 || 더 많이 생성 
    return false; // 모자르게 생성
}

void findSize(long long start, long long end){
    if(start > end) return;
    long long mid = (start + end) / 2;
    if(check(mid)){
        if(canCut < mid)
            canCut = mid;
        findSize(mid + 1, end);
    } else findSize(start, mid - 1);
}

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> K >> N;

    for(int i = 0; i < K; i++)
        cin >> lan[i];

    sort(lan, lan + K);
    // long long low = 1;
    // long long high = lan[K-1];
    // while(low <= high){
    //     long long mid = (low + high) / 2;
    //     if (check(mid)){
    //         if (canCut < mid)
    //             canCut = mid;
    //         low = mid + 1;
    //     }
    //     else high = mid - 1;
    // }
    findSize(1, lan[K - 1]); // 가장 긴 랜선 길이
    cout << canCut;
    return 0;
}


// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int MAX = 10000;

// int N, M;
// long long electricLine[MAX];

// bool possible(long long len){
//         int cnt = 0;
//         for (int i = 0; i < N; i++)
//              cnt += electricLine[i] / len;

//         if (cnt >= M)
//                  return true;
//         return false;
// }

// int main(void){
//         ios_base::sync_with_stdio(0);
//         cin.tie(0);
//         cin >> N >> M;

//         long long high = 0;
//         for (int i = 0; i < N; i++){
//                  cin >> electricLine[i];
//                  high = max(high, electricLine[i]);
//         }

//         long long result = 0;
//         long long low = 1;
//         while (low <= high)
//         {
//                  long long mid = (low + high) / 2;
//                  if (possible(mid))
//                  {
//                          if (result < mid)
//                                  result = mid;
//                          low = mid + 1;
//                  }
//                  else
//                          high = mid - 1;
//         }
//         cout << result << "\n";
//         return 0;
// }