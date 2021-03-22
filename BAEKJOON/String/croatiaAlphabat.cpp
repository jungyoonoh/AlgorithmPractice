#include <iostream>
#include <string>
#define SIZE 8
using namespace std;

string str, croatia[SIZE] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
int checkCroatia(int idx){
    string substr;
    int size = 0;
    bool flag = true;
    if(idx == str.size() - 1) return 1;
    if(idx == str.size() - 2) flag = false; // 3글자 X   
    for(int i = 0; i < SIZE; i++){
        if(i == 2 && flag) size = 3;
        else size = 2;
        substr = str.substr(idx,size);
        if(croatia[i] == substr) return size;
    }
    return 1;
}

int main(){
    cin >> str;
    int cnt = 0;
    for(int i = 0; i < str.size(); ){
        int ret = checkCroatia(i);
        i += ret;
        cnt++;
    }
    cout << cnt;
    return 0; 
}