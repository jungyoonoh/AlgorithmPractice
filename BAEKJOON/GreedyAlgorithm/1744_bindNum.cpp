#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, input;
long long sum = 0;
int main(){
    cin >> N;
    priority_queue <int, vector<int>, less<int>> pqPlus;
    priority_queue <int, vector<int>, greater<int>> pqMinus; 
    for(int i = 0; i < N; i++){
        cin >> input;
        if(input > 0) pqPlus.push(input);
        else pqMinus.push(input);
    }
    long long n1, n2;
    while(pqPlus.size() > 1){
        n1 = pqPlus.top();
        pqPlus.pop();        
        n2 = pqPlus.top();
        pqPlus.pop();
        if(n1 == 1 || n2 == 1){
            sum += n1 + n2;
            break;
        } 
        sum += n1 * n2;
    }
    while(pqMinus.size() > 1){
        n1 = pqMinus.top();
        pqMinus.pop();        
        n2 = pqMinus.top();
        pqMinus.pop();
        sum += n1 * n2;
    }
    while(!pqPlus.empty()){
        sum += pqPlus.top();
        pqPlus.pop();
    }    
    while(!pqMinus.empty()){
        sum += pqMinus.top();
        pqMinus.pop();
    }    
    cout << sum;
    
    return 0;
}