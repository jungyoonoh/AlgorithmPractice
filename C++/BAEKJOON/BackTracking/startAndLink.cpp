#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int N, ability[20][20], gap = 2147483647, teamStart, teamLink, startNum = 0, linkNum = 0; 
int team[20]; // start : 0, Link : 1

void calculateAbility(){
    teamStart = teamLink = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(i != j && team[i] == team[j])
                team[i] == 0 ? teamStart += ability[i][j] : teamLink += ability[i][j];
    gap = min(gap, abs(teamStart - teamLink));
}

void makeTeam(int num){ 
    if(startNum + linkNum == N) {calculateAbility(); return;}
    // startTeam.
    if(N/2 - startNum > 0){
        if(team[num] == -1){
            team[num] = 0;
            startNum++;
            makeTeam(num+1);
            team[num] = -1;
            startNum--;
        }
    }

    // linkTeam
    if(N/2 - linkNum > 0){
        if(team[num] == -1){
            team[num] = 1;
            linkNum++;
            makeTeam(num+1);
            team[num] = -1;
            linkNum--;
        }
    }
}

int main(){
    cin >> N;
    for(int i=0; i< N; i++)
        for(int j=0; j< N; j++)
            cin >> ability[i][j];
    memset(team,-1,sizeof(team));   
    makeTeam(0); 
    cout << gap;
    return 0;
}