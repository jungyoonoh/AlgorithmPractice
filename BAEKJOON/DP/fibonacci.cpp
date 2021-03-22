#include <iostream>
#include <string.h>

using namespace std;
int n;
long long cache[50];
long long fibonacci(int num) {
    if (num == 0) 
        return cache[0] = 0;
    else if (num == 1)
        return cache[1] = 1;        
    long long& ret = cache[num];
    if(ret != -1)
        return ret;
    return ret = fibonacci(num-1) + fibonacci(num-2);
}


int main(){
    int TC;
    cin >> TC;
    while(TC--){
        memset(cache,-1,sizeof(cache));
        cin >> n;
        if(n == 0)
            cout << "1 0" << endl;
        else
            cout << fibonacci(n-1) << " " << fibonacci(n) << endl;
    }    
    return 0;
}