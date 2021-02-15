#include <iostream>
#include <algorithm>

using namespace std;

int stairsNum, sav = 0;
int stairs[301];
int cache[301] = {0, }; // -> ����

// 1. �ѹ��� 1�� or 2�� ���
// 2. ���ӵ� 3���� ��� X
// 3. �������� �ݵ�� ��ƾ�
// ���� �ʴ� ��츦 ĳ�÷� ������ ������ �����Ƿ� ���縦 ��� ��츸 ����
int ascend(){
    for(int i = 0; i < 3; i++) // ����� 1�� ~ 3�����
        i == 0 ? cache[i] = stairs[i] : i == 1 ? cache[i] = stairs[i] + stairs[i-1] : cache[i] = max(stairs[i] + stairs[i-1], stairs[i] + stairs[i-2]);
    
    for(int i = 3; i < stairsNum; i++) // ����� 4�� �̻��̶�� 
        cache[i] = max(cache[i-2] + stairs[i], cache[i-3] + stairs[i-1] + stairs[i]); 
        
    return cache[stairsNum - 1];
}

int main(){
    cin >> stairsNum;
    for(int i = 0; i < stairsNum; i++) 
        cin >> stairs[i];
    cout << ascend() << endl;
    return 0;
}