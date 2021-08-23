#include <iostream>

using namespace std;

// MSB = Most Significant Bit
// MSB : ���� ū �ڸ����� ��Ʈ (���� ���� ��Ʈ)
// LSB = Least Significant Bit
// LSB : ���� ���� �ڸ����� ��Ʈ (���� ������ ��Ʈ)

int Blefuscu[32];
int Lillput[32];
unsigned int indianNum;
unsigned int convertNum;

void convert(unsigned int num){
    // 16������ 2���� 4���� ���� ����
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