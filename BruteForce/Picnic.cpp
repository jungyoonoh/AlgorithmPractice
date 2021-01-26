#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int relationship[77][77]; 
int checkMatching[77]; 
int C,n,m,sol;

void Matching() {
	int iterator = -1;
	for (int i = 0; i < n; i++) {
		if (checkMatching[i] == 0) {
			iterator = i;
			break;
		}
	}
	if (iterator == -1) { // 친구 매칭 다됨 == case 발견
		sol++;
		return;
	}
	for (int i = iterator+1; i < n; i++) {
		if (checkMatching[i] == 0 && checkMatching[iterator] == 0 && relationship[i][iterator] == 1) { // 현재 짝 아니면서 친구인 애들
			checkMatching[i] = checkMatching[iterator] = 1;
			Matching();
			checkMatching[i] = checkMatching[iterator] = 0; 
		}
	}
}

void reset(){
    for(int i = 0; i < 77; i++){
        for(int j = 0; j < 77; j++){
            relationship[i][j] = 0;
        }
        checkMatching[i] = 0;
    }
    sol = 0;
}

int main(){

    cin >> C;
    while(C--){
        reset();
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int n1, n2;
            cin >> n1 >> n2;
            relationship[n1][n2] = relationship[n2][n1] = 1;
        }
        Matching();
        cout << sol << endl;
    }
    return 0;
}