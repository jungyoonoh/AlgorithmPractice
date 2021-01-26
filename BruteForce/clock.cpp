#include <iostream>
using namespace std;
#define CLOCK_NUM 16
#define SWITCH_NUM 10

// 스위치 리스트
int Switch[SWITCH_NUM][CLOCK_NUM] = {
	{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 }, // 0
{ 0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0 }, // 1
{ 0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1 }, // 2
{ 1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 }, // 3
{ 0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0 }, // 4
{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1 }, // 5
{ 0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1 }, // 6
{ 0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1 }, // 7
{ 0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0 }, // 8
{ 0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0 }, // 9
};

int remainCheckSwitch[SWITCH_NUM][CLOCK_NUM] = {
	{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 }, // 0
	{ 0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0 }, // 1
	{ 0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1 }, // 2
	{ 1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 }, // 3
	{ 0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0 }, // 4
	{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1 }, // 5
	{ 0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1 }, // 6
	{ 0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1 }, // 7
	{ 0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0 }, // 8
	{ 0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0 }, // 9
};
int Clock[16] = { 0,};

// 8,11,12,13 // 4,1,4,9
// 6,7,8,12
// 3,7,9,11
// 6,7,8,10,12
// 3,4,5,9,13
// 3 ~ 13 o, 0,1,2,14,15.
void reset() {
	for (int i = 0; i < SWITCH_NUM; i++)
		for (int j = 0; j < CLOCK_NUM; j++) 
			remainCheckSwitch[i][j] = Switch[i][j];
}

void checkRemain(int* SN, int* CN) {
	*SN = *CN = 0;
	for (int i = 0; i < CLOCK_NUM; i++) {
		int sum = 0;
		for (int j = 0; j < SWITCH_NUM; j++) {
			if (remainCheckSwitch[j][i] != 0) {
				sum++;
				*SN = j;
				*CN = i;
			}
		}
		if (sum == 1) {
			for (int k = 0; k < CLOCK_NUM; k++)
				remainCheckSwitch[*SN][k] = 0;
			return;
		}
	}
}

int rotate(int SN, int CN) {
	int rotateNum = (4 - Clock[CN]) % 4;
	for (int i = 0; i < CLOCK_NUM; i++) {
		if (Switch[SN][i]) // 스위치에 연결된 시계라면
			(Clock[i] += rotateNum) %= 4; // 시계 갱신
	}
	return rotateNum;
}

int main() {
	int caseNum;
	cin >> caseNum;
	int* result = new int[caseNum];
	int SN, CN, cnt,tryNum;

	for (int a = caseNum; a > 0; a--) {
		reset();
		SN = CN = tryNum = 0;
		for (int i = 0; i < CLOCK_NUM; i++) {
			cin >> Clock[i];
			(Clock[i] /= 3) %= 4;
		}
		for (int i = 0; i < SWITCH_NUM; i++) {
			checkRemain(&SN, &CN);
			tryNum += rotate(SN, CN);
		}
		for (cnt = 0; cnt < CLOCK_NUM; cnt++) {
			if (Clock[cnt]) {
				result[caseNum - a] = -1;
				break;
			}
		}
		if (cnt == CLOCK_NUM)
			result[caseNum - a] = tryNum;
	}
	
	for (int i = 0; i < caseNum; i++) {
		cout << result[i] << endl;
	}
	delete result;
	return 0;
}