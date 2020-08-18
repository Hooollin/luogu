//
// P1536.cpp 
// Created by Hollin on 8/15/2020
//

#include <bits/stdc++.h>
#include <fstream>

using namespace std;

const int maxn = 1001;
int p[maxn];

int f(int x){
    if(p[x] == -1 || p[x] == x){
        return x;
    }
    p[x] = f(p[x]);
    return p[x];
}

void u(int x, int y){
    x = f(x);
    y = f(y);
    p[x] = y;
}

int main(){
    while(1){
        int m, n;
        cin >> m;
        if(m == 0){
            break;
        }
        memset(p, -1, sizeof(p));
        cin >> n;
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            u(x, y);
        }
        int ans = 0;
        for(int i = 1; i <= m ; i++){
            //cout << p[i] << endl;
            ans += p[i] == -1 || p[i] == i;
        }
        cout << max(ans - 1, 0) << endl;
    }
    return 0;
}