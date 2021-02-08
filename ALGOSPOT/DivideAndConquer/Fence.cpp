#include <iostream>
using namespace std;

int solve(int** height, int fenceNum,int tryNum) {
	int rightIndex, leftIndex, max;
	int savMax = 0;
	height[tryNum][0] = 0; // ó������ ���� ���� X, ���� ���� ����
	height[tryNum][fenceNum + 1] = 0; // �� ���� -> ������ ���� ����
	int* savIndex = new int[fenceNum];
	savIndex[0] = 0; // ������
	int Iterator = 0;
	for (int i = 1; i <= fenceNum + 1; i++) {
		rightIndex = i;
		int maxHeightIndex;
		if ((height[tryNum][savIndex[Iterator]] == height[tryNum][rightIndex]) && height[tryNum][rightIndex] > 0)
			continue;

        // ����� ���̰� �����ϴ� ���� = �� ���� ��������
		while (height[tryNum][savIndex[Iterator]] > height[tryNum][rightIndex]) { // ���� ���� ã�� 
			maxHeightIndex = savIndex[Iterator--]; 
			leftIndex = savIndex[Iterator]; 
			max = (rightIndex - leftIndex - 1) * height[tryNum][maxHeightIndex]; // ���� ������ right 
			if (savMax < max)
				savMax = max;
		}
		savIndex[++Iterator] = i; // ������ ���� && ������ ��� X�� idx�� ����
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