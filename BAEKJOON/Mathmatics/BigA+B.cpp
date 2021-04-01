#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string A,B, temp, res;
    cin >> A >> B;
    if(A.size() < B.size()){
        for(int i = 0; i < B.size() - A.size(); i++)
            temp += '0';            
        A = temp + A;
    } else {
        for(int i = 0; i < A.size() - B.size(); i++)
            temp += '0';
        B = temp + B;
    }

    int carry = 0, sum;
    while (A.size()!=0 && B.size() !=0){
        int S = A.back() - '0'; 
        int V = B.back() - '0'; 
        int remain = (carry + S + V) % 10;
        carry = (carry + S + V) / 10; 
        res = (char)(remain + '0') + res;
        A.pop_back();
        B.pop_back();
    }

    if(carry == 1) res = (char)(carry + '0') + res;
    cout << res;
    return 0;
}