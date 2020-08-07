//
// P1162.cpp 
// Created by Hollin on 7/31/2020
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 31;
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};
int mat[maxn][maxn];

void dfs(int i, int j, int n){
    if(i < 0 || i >= n || j < 0 || j >= n || mat[i][j] == 1 || mat[i][j] == 3){
        return;
    }
    mat[i][j] = 3;
    for(int k = 0; k < 4; k++){
        int nx = i + dx[k], ny = j + dy[k];
        dfs(nx, ny, n);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        if (mat[i][0] == 0) {
            dfs(i, 0, n);
        }
        if(mat[i][n - 1] == 0){
            dfs(i, n - 1, n);
        }
        if(mat[0][i] == 0){
            dfs(0, i, n);
        }
        if(mat[n - 1][i] == 0){
            dfs(n - 1, i, n);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 3){
                cout << 0 << " ";
            }else if(mat[i][j] == 1){
                cout << 1 << " ";
            }else cout << 2 << " ";
        }
        cout << endl;
    }
    return 0;
}