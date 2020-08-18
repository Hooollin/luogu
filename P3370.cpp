//
// P3370.cpp 
// Created by Hollin on 8/17/2020
//
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1e6 + 1;
ull table[maxn];
const int p = 7;

ull hash(string s){
    ull now = 0;
    for(int i = 0; i < s.size(); i++){
        now = now * 7 + (ull)(s[i] - 'a' + 1);
    }
    return now;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        table[i] = hash(s);
    }
    sort(table, table + n);
    int ans = 1;
    for(int i = 1; i < n; i++){
        ans += table[i] != table[i - 1];
    }
    cout << ans << endl;
    return 0;
}