#include <iostream>

using namespace std;

int score[1001];
int main(){
    int C,N;
    double avg;
    cin >> C;
    for(int i = 0; i < C; i++){
        cin >> N;
        double sum = 0,aboveAvg = 0;
        for(int j = 0; j < N; j++){
            cin >> score[j];
            sum += score[j];
        }
        avg = sum / N;
        for(int j = 0; j < N; j++){
            if(avg < score[j])
                aboveAvg++;
        }
        cout << fixed;
        cout.precision(3);
        cout << aboveAvg / N * 100 << "%\n";
    }
    return 0;
}