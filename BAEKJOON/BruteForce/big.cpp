#include <iostream>

using namespace std;

struct big{
    int x,y,cnt=1;
};

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    int N;
    cin >> N;
    big person[50];
    for(int i = 0; i < N; i++){
        cin >> person[i].x;
        cin >> person[i].y;
    }
    for(int i = 0 ; i < N; i++){
        for(int j = i+1; j < N; j++){
            if((person[i].x > person[j].x) && (person[i].y > person[j].y)) person[j].cnt++;
            else if((person[i].x < person[j].x) && (person[i].y < person[j].y)) person[i].cnt++;
        }
    }
    for(int i = 0; i < N; i++)
        cout << person[i].cnt << " ";
    return 0;    
}