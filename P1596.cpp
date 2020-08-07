//
// P1596.cpp 
// Created by Hollin on 7/31/2020
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
const int dirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
char mat[maxn][maxn];

void dfs(int x, int y, int n, int m){
    if(x < 0 || x >= n || y < 0 || y >= m || mat[x][y] == '#' || mat[x][y] == '.'){
        return;
    }
    mat[x][y] = '#';
    for(auto p : dirs){
        int nx = x + p[0], ny = y + p[1];
        dfs(nx, ny, n, m);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            if (mat[i][j] == 'W') {
                dfs(i, j, n, m);
                ans += 1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}