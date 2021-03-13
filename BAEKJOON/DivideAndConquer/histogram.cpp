#include <iostream>
#include <algorithm>

using namespace std;

long long histogram[100001], n;

long long findRect(int left, int right){
    if(left == right) return histogram[left]; // 기저사례

    int mid = (left + right) / 2;
    long long ret = max(findRect(left,mid), findRect(mid+1,right));

    long long lIter = mid, rIter = mid + 1;
    long long height = min(histogram[lIter], histogram[rIter]); 

    ret = max(ret, height * 2);

    while(left < lIter || rIter < right){
        if(rIter < right && (left == lIter || histogram[lIter - 1] < histogram[rIter + 1])) { // 끝 도달 or 더 높음
            rIter++;
            height = min(height, histogram[rIter]);
        } else if (left < lIter && (right == rIter || histogram[lIter - 1] >= histogram[rIter + 1])) {
            lIter--;
            height = min(height, histogram[lIter]);
        }
        ret = max(ret, (rIter - lIter + 1) * height);
    }
    return ret;
}

int main(){
    cin.tie(NULL); cin.sync_with_stdio(false);
    while(true){
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++)
            cin >> histogram[i];
        cout << findRect(0,n - 1) << '\n';
    }
    return 0;    
}