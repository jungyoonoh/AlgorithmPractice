#include <iostream>
#include <string>
#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

using namespace std;
int TC, L, R, U, D, dir, dx, dy, x, y;
string str;
int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    cin >> TC;
    while(TC--){
        cin >> str;
        x = y = L = R = U = D = 0;
        dir = UP;
        for(int i = 0; i < str.size(); i++){
            if(str.at(i) == 'L')
                dir = (dir + 1) % 4;             
            else if (str.at(i) == 'R')
                dir = (dir + 3) % 4;
            
            switch(dir){
                case UP: dx = 0; dy = -1;
                    break;
                case LEFT: dx = -1; dy = 0;
                    break;
                case DOWN: dx = 0; dy = 1;
                    break;
                case RIGHT: dx = 1; dy = 0;
                    break;
            }
            if(str.at(i) == 'F'){                
                x += dx;
                y += dy;
            }else if (str.at(i) == 'B'){
                x -= dx;
                y -= dy;
            }
            if(x > 0) R = max(R,x);
            if(x < 0) L = min(L,x);
            if(y > 0) U = max(U,y);
            if(y < 0) D = min(D,y);
        }
        cout << (R - L) * (U - D) << endl;
    }
    return 0;
}