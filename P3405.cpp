//
// P3405.cpp 
// Created by Hollin on 8/18/2020
// 
#include <bits/stdc++.h>
using namespace std;
map<string, map<string, int>> m;
int main(){
    int n;
    cin >> n;
    string s, t;
    int ans = 0;
    while(n-- > 0) {
        cin >> s >> t;
        s = s.substr(0, 2);
        if(s != t){
            ans += m[t][s];
            m[s][t] += 1;
        }
    }
    cout << ans << endl;
    return 0;
}