#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>

using namespace std;

int N,M,crane[50],box[10000], canPick[50];

int main(){    
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> crane[i];
    cin >> M;
    for(int i = 0; i < M; i++)
        cin >> box[i];
    
    sort(crane, crane+N);
    sort(box, box+M);
    memset(canPick, 0, sizeof(canPick));
    int idx = 0;

    if(crane[N-1] < box[M-1]) {cout << -1; return 0;}

    for(int i = 0; i < M; i++){
        if(crane[idx] < box[i]){
            idx++;
            i--;
        }else canPick[idx]++;
    }
    
    int time = 0, cnt = 0;
    while(1){
        for(int i = N - 1; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                if(canPick[j] > 0) {
                    canPick[j]--;
                    cnt++;                     
                    break;
                }
            }
            if(cnt == M) break;
        }
        time++;
        if(cnt == M) break;
    }
    cout << time;
    return 0;
}




// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// vector<int> crane, box;
// int avail[10000];

// int main() {
// 	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// 	int c, num, val;
// 	cin >> c;
// 	for (int i = 0; i < c; i++) {
// 		cin >> val;
// 		crane.push_back(val);
// 	}
// 	sort(crane.begin(),crane.end());
// 	cin >> num;
// 	for (int i = 0; i < num; i++) {
// 		cin >> val;
// 		box.push_back(val);
// 	}
// 	sort(box.begin(), box.end());
// 	if (crane[c - 1] < box[num - 1]) {
// 		cout << -1;
// 		return 0;
// 	}
// 	int idx = 0;
// 	for (int i = 0; i < num; i++) {
// 		if (crane[idx] >= box[i]) 	avail[idx]++;		
// 		else {
// 			idx++;
// 			i--;
// 		}
// 	}
// 	int cnt = 0, t = 0;
// 	while (1) {
// 		for (int i = c - 1; i >= 0; i--) {
// 			for (int j = i; j >= 0; j--) {
// 				if (avail[j]) {
// 					avail[j]--;
// 					cnt++;
// 					break;
// 				}
// 			}
// 			if (cnt == num) break;
// 		}
// 		t++;
// 		if (cnt == num) break;
// 	}
// 	cout << t;
// 	return 0;
// }