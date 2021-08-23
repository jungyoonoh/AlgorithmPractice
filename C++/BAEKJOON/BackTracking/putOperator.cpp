#include <iostream>
#include <algorithm>

using namespace std;
int N, sequence[11], operatorNum[4], minSequence = 2147483647, maxSequence = -2147483647;

void findExperssion(int size, int sum){
    if(size == N){
        minSequence = min(minSequence,sum);
        maxSequence = max(maxSequence,sum);
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < operatorNum[i]; j++){
            operatorNum[i]--;
            switch(i){ // + - x / 
                case 0:
                    findExperssion(size+1, sum+sequence[size]);
                    break;
                case 1:
                    findExperssion(size+1, sum-sequence[size]);
                    break;
                case 2:
                    findExperssion(size+1, sum*sequence[size]);
                    break;
                case 3:
                    findExperssion(size+1, sum/sequence[size]);
                    break;
            }
            operatorNum[i]++;
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> sequence[i];
    for(int i = 0; i < 4; i++) cin >> operatorNum[i];
    
    findExperssion(1,sequence[0]);
    cout << maxSequence << '\n';
    cout << minSequence << '\n';
    return 0;
}