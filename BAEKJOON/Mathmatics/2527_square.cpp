#include <iostream>
#include <deque>

using namespace std;

int x1,y1,x2,y2;

struct square{
    int x1,y1,x2,y2;
};

deque<square> squareList;

char find(){
    square s1 = squareList.front();
    squareList.pop_front();
    square s2 = squareList.front();
    squareList.pop_front();
    if((s1.x2 == s2.x1 && s1.y2 != s2.y1) || (s1.x2 == s2.x1 && s1.y1 != s2.y2) || (s1.x1 != s2.x2 && s1.y2 == s2.y1) || (s1.x1 != s2.x2 && s1.y1 == s2.y2)) return 'b';
    else if((s1.x2 == s2.x1 && s1.y2 == s2.y1) || (s1.x2 == s2.x1 && s1.y1 == s2.y2) || (s1.x1 == s2.x2 && s1.y2 == s2.y1) || (s1.x1 == s2.x2 && s1.y1 == s2.y2)) 
        return 'c';
    else if(s1.x2 < s2.x1 || s2.x2 < s1.x1 || s1.y2 < s2.y1 || s2.y2 < s1.y1)
        return 'd';
    else return 'a';

    // case a : 두 직사각형이 겹치는 경우
    
    // case b : 두 직사각형이 선으로 겹치는 경우
    
    // case c : 두 직사각형이 점으로 겹치는 경우
    
    // case d : 두 직사각형이 안겹치는 경우

    // a,b,c 하고 아니면 d
}

int main(){
    for(int i = 0; i < 4; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        square temp = {x1,y1,x2,y2};
        squareList.push_back(temp);
        cin >> x1 >> y1 >> x2 >> y2;
        square temp = {x1,y1,x2,y2};
        squareList.push_back(temp);
    }
    for(int i = 0; i < 4; i++){
        find();
    }
    // 한번에 2 사각형씩 비교

    return 0;
}