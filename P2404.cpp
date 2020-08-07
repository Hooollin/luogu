//
// P2404.cpp 
// Created by Hollin on 7/31/2020
//
#include <bits/stdc++.h>
using namespace std;

void bt(string now, int pmin, int n){
    if(n == 0){
        cout << now << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(i >= pmin) bt(now + "+" + char(i + '0'), i, n - i);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n / 2; i++){
        bt(to_string(i), i, n - i);
    }
    return 0;
}