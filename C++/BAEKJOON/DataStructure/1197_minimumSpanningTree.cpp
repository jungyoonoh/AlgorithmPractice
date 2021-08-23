#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int V,E,parent[10001], A,B,C,ans = 0,cnt = 0;
vector<pair<int, pair<int, int>>> G;

int find(int a){
    if(parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

int main(){
    cin >> V >> E;
    memset(parent, 0, sizeof(parent));
    for(int i = 0; i < E; i++){
        cin >> A >> B >> C;
        G.push_back({C, {A,B}});         
    }

    // V의 개수가 E개수보다 적을 수 있음
    for(int i = 1; i <= V; i++) 
        parent[i] = i;

    sort(G.begin(), G.end());

    // 서로 같은 부모인지
    // 다르면(연결이 안되어있다는 뜻) 연결하기
    
    for(int i = 0; i < E; i++){
        int n1 = find(G.at(i).second.first);
        int n2 = find(G.at(i).second.second);
        // 서로 연결되어있지않으면
        if(n1 != n2){
            parent[n1] = n2;
            ans += G.at(i).first;
            cnt++;
        }
        if(cnt == V - 1) break;
    }
    cout << ans;
    return 0;
}