#include <iostream>
using namespace std;

int tc;
int row, col;
char board[20][20]; // 0 = white , 1 = black
int ans = 0;

// 상대 이동좌표
const int coverType[4][3][2] = {
	{{0,0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
};

bool covercheck(int y, int x, int type, int set)
{
	bool check = true;
	for (int i = 0; i < 3; i++)
	{
		int ny = y + coverType[type][i][0];
		int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= row || nx < 0 || nx >= col) check = false; // 판넘어감
		else if ((board[ny][nx] += set) > 1) check = false; // 겹침
	}
	return check;
}

int search() {

	int y = -1;
	int x = -1;

	// 좌표찾기
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)
			break;
	}
	// 다덮음
	if (y == -1)
		return 1;

	// 탐색 시작
	int ans = 0;
	for (int t = 0; t < 4; t++) {
		if (covercheck(y, x, t, 1))
			ans += search();
		covercheck(y, x, t, -1);
	}
	return ans;
}

void init() {
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			board[i][j] = 0;
}


int main() {
	cin >> tc;
	char temp;
	while (tc--) {
		int cnt = 0;
		cin >> row >> col;
		init();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> temp;
				board[i][j] = (temp == '#') ? 1 : 0;
				if (board[i][j]) cnt++; // 검은칸의 수
			}
		}
		int remain = row * col;
		remain -= cnt; // 전체 - 검은 = 흰
		if (remain % 3 != 0) {
			cout << 0 << endl;
			continue;
		}
		cout << search() << endl;
	}

	return 0;
}