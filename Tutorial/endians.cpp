#include <iostream>

using namespace std;

// MSB = Most Significant Bit
// MSB : 가장 큰 자릿수의 비트 (가장 왼쪽 비트)
// LSB = Least Significant Bit
// LSB : 가장 작은 자릿수의 비트 (가장 오른쪽 비트)

int Blefuscu[32];
int Lillput[32];
unsigned int indianNum;
unsigned int convertNum;

void convert(unsigned int num){
    // 16진수는 2진수 4개씩 끊어 읽음
    unsigned int byte1 = (num & 0x000000ff) << 24;
    unsigned int byte2 = (num & 0x0000ff00) << 8;
    unsigned int byte3 = (num & 0x00ff0000) >> 8;
    unsigned int byte4 = (num & 0xff000000) >> 24;
    unsigned int convertNum = byte1 + byte2 + byte3 + byte4;
    cout << convertNum << endl;
}

void init(){
    for(int i = 0; i < 32; i++){
        Blefuscu[i] = 0;
        Lillput[i] = 0;
    }
    indianNum = 0;
    convertNum = 0;
}

int main(){
    int C;
    cin >> C;
    while(C--){
        init();
        cin >> indianNum;
        convert(indianNum);
    }
    return 0; 
}