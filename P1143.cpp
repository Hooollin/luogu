#include <iostream>

using namespace std;

long long fp(int x, int k){
    if(k == 0) return 1;
    long long val = fp(x, k / 2);
    return k % 2 ? val * val * x : val * val;
}

void convert(long long n, int k){
    if(n == 0){
        return;
    }
    convert(n / k, k);
    int rem = n % k;
    if(rem >= 10){
        cout << (char)('A' + rem - 10);
    }else{
        cout << rem;
    }
}

int main(){
    // from n -> k
    int n, k;
    string input;
    cin >> n >> input >> k;

    long long num = 0;
    for(int i = 0; i < input.size(); i++){
        if(input[i] >= '0' && input[i] <= '9'){
            num += (input[i] - '0') * fp(n, (input.size() - i) - 1);
        }else if(input[i] >= 'A'){
            num += (input[i] - 'A' + 10) * fp(n, (input.size() - i) - 1);
        }
    }
    convert(num, k);
    return 0;
}
