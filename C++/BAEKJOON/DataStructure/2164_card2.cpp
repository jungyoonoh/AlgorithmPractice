#include <iostream>
#include <deque>

using namespace std;

deque<int> card;
int N;
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++)
        card.push_back(i);
    
    while(card.size() != 1){
        card.pop_front();
        card.push_back(card.front());
        card.pop_front();
    }
    cout << card.front();
    return 0;
}