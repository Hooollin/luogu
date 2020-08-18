//
// BattleforWosneth.cpp 
// Created by Hollin on 8/9/2020
//

#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

long long quickpow(long long a, long long b) {
    if (b < 0) return 0;
    long long ret = 1;
    a %= mod;
    while(b) {
        if (b & 1) ret = (ret * a) % mod;
        b >>= 1;
        a=(a*a) % mod;
    }
    return ret;
}
long long inv(long long a) {
    return quickpow(a, mod - 2);
}

int main(){
    int n;
    cin >> n;
    while(n-- > 0){
        long long m, p, q;
        cin >> m >> p >> q;
        long long a = m * p * 100 - m * (100 - p) * q - (m - 1) * q * p;
        long long b = p * 100;
        long long t = __gcd(a, b);
        a /= t;
        b /= t;
        if(a % b == 0){
            cout << a / b % mod<< endl;
        }else{
            cout << (a * inv(b) + mod) % mod << endl;
        }
    }
    return 0;
}