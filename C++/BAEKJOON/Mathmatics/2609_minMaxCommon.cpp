#include <iostream>

using namespace std;

int main(){
    int A, B, i = 1, divide = 1, multiple = 1;
    cin >> A >> B;
    int TA = A, TB = B;
    while(i < A && i < B){
        i++;
        if(A % i == 0 && B % i == 0){            
            divide *= i;
            A /= i; 
            B /= i;
            i = 1;            
        }        
    }

    multiple = (TA * TB) / divide;
    cout << divide << '\n' << multiple;
    return 0;
}