#include <iostream>

using namespace std;

int xy[3][2];
int ans[2];
void solve(){

    // ���ο� ����
    // ans[0] = xy[0][0] ^ xy[1][0] ^ xy[2][0]; 
    // ans[1] = xy[0][1] ^ xy[1][1] ^ xy[2][1]; 
    // -> x���� ���� �� �༮�� XOR ��Ʈ������ 0�� �����
    // ��ȯ��Ģ�� �����ϱ⿡ 3���� 2���� ���� ������ 1���� ���� �״�� ����

    // ��
    if(xy[0][0] == xy[1][0])
        ans[0] = xy[2][0];
    else if(xy[0][0] == xy[2][0])
        ans[0] = xy[1][0];
    else if(xy[1][0] == xy[2][0])
        ans[0] = xy[0][0];

    if(xy[0][1] == xy[1][1])
        ans[1] = xy[2][1];
    else if(xy[0][1] == xy[2][1])
        ans[1] = xy[1][1];
    else if(xy[1][1] == xy[2][1])
        ans[1] = xy[0][1];

    cout << ans[0] << " " << ans[1] << endl;   
}

int init(){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 2; j++)
            xy[i][j] = 0;
    ans[0] = ans[1] = 0;
}

int main(){
    int T;
    cin >> T;
    while (T--){
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 2; j++)
                cin >> xy[i][j];

        solve();
    }
    return 0;
}