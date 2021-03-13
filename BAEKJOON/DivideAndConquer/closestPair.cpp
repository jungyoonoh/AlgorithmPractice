#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define MIN_DIST 2111111111

using namespace std;

// Closest Pair�� ����ϴ� ��ǥ���� ����
// �ݵ�� ����
// ���̵��� �� ����

struct Coordinates{
    int x, y;
};

vector<Coordinates> dots;

bool compareX(Coordinates a, Coordinates b){
    return a.x < b.x;
}

bool compareY(Coordinates a, Coordinates b){
    return a.y < b.y;
}

int dist(Coordinates a, Coordinates b){
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

int closestPair(int left, int right){
    if(left == right) return MIN_DIST;

    int mid = (left + right) / 2;
    int ret = min(closestPair(left, mid),closestPair(mid+1, right));

    // ���� �� �� �ִ� �ĺ��� Ž�� (x ����)
    vector<Coordinates> dotList;
    for(int i = left; i <= right; i++){
        int distance = abs(dots[mid].x - dots[i].x);
        if(distance * distance < ret) dotList.push_back(dots[i]);
    }

    sort(dotList.begin(), dotList.end(), compareY);
    
    for(int i = 0; i < dotList.size(); i++){
        for(int j = i + 1; j < dotList.size(); j++){
            int temp = dotList[j].y - dotList[i].y;
            if(temp * temp < ret) // �������� �����̹Ƿ�
                ret = min(ret, dist(dotList[i], dotList[j]));
            else break;
        }
    }

    return ret;
}

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    int n,x,y;
    cin >> n;
    Coordinates temp;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        temp.x = x; temp.y = y;
        dots.push_back(temp);
    }
    sort(dots.begin(), dots.end(), compareX);
    cout << closestPair(0, n - 1);
    return 0;
}