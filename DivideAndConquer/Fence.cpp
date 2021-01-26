#include <iostream>
using namespace std;

int solve(int** height, int fenceNum,int tryNum) {
	int rightIndex, leftIndex, max;
	int savMax = 0;
	height[tryNum][0] = 0; // 처음부터 낙하 지점 X, 증가 구간 설정
	height[tryNum][fenceNum + 1] = 0; // 끝 지점 -> 마지막 낙하 설정
	int* savIndex = new int[fenceNum];
	savIndex[0] = 0; // 최저점
	int Iterator = 0;
	for (int i = 1; i <= fenceNum + 1; i++) {
		rightIndex = i;
		int maxHeightIndex;
		if ((height[tryNum][savIndex[Iterator]] == height[tryNum][rightIndex]) && height[tryNum][rightIndex] > 0)
			continue;

        // 블록의 높이가 낙하하는 지점 = 블럭 생성 분할지점
		while (height[tryNum][savIndex[Iterator]] > height[tryNum][rightIndex]) { // 낙하 지점 찾기 
			maxHeightIndex = savIndex[Iterator--]; 
			leftIndex = savIndex[Iterator]; 
			max = (rightIndex - leftIndex - 1) * height[tryNum][maxHeightIndex]; // 낙하 지점이 right 
			if (savMax < max)
				savMax = max;
		}
		savIndex[++Iterator] = i; // 증가세 였음 && 위에서 사용 X인 idx만 갱신
	}
	return savMax;
}


int main() {
	int caseNum;
	cin >> caseNum;
	int* result = new int[caseNum];
	int fenceNum;
	int max = 0;
	int min = 0;
	int** height = new int*[caseNum];

	for (int i = 0; i < caseNum; i++) {
		cin >> fenceNum;
		height[i] = new int[fenceNum + 2];
		for (int j = 1; j <= fenceNum; j++) 
			cin >> height[i][j];
		result[i] = solve(height, fenceNum, i);
	}

	for (int i = 0; i < caseNum; i++)
		cout << result[i] << endl;

	delete result;

	return 0;
}