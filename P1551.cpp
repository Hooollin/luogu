//
// P1551.cpp 
// Created by Hollin on 8/15/2020
//

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 1;
int fa[maxn];

int find(int x){
    if(fa[x] == -1){
        return x;
    }
    fa[x] = find(fa[x]);
    return fa[x];
}

bool uni(int x, int y){
    x = find(x), y = find(y);
    if(x == y){
        return false;
    }
    fa[x] = y;
    return true;
}

int main(){
    memset(fa, -1, sizeof(fa));
    int n, m, p;
    cin >> n >> m >> p;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        uni(x, y);
    }
    for(int i = 0; i < p; i++){
        int x, y;
        cin >> x >> y;
        if(find(x) == find(y)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}