#include <iostream>
#include <cmath>
using namespace std;

void convert(int n, int R){
    if(n == 0){
        return;
    }
    convert(n / abs(R), R);
    int rem = n % abs(R);
    if(rem > 10){
        cout << (char)(rem + 'A');
    }else{
        cout << rem;
    }
}

int main(){
    int n, R;
    cin >> n >> R;
    convert(abs(n), R);
    printf("(base%d)", R);
    return 0;
}