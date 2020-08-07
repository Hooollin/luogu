//
// P1443.cpp 
// Created by Hollin on 7/29/2020
//
#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e2 + 1;
const int inf = 1e4 + 1;

int dir[8][2] = {{-1, -2}, {-2, -1}, {2, -1}, {1, -2}, {-2, 1}, {-1, 2}, {2, 1}, {1, 2}};
int mat[maxn][maxn];
int vis[maxn][maxn];

void dfs(int x, int y, int n, int m, int dis){
    mat[x][y] = dis;
    for(auto d : dir){
        int nx = x + d[0], ny = y + d[1];
        if(nx > 0 && nx <= n && ny > 0 && ny <= m && mat[nx][ny] > dis + 1){
            dfs(nx, ny, n, m, dis + 1);
        }
    }
}

int main(){
    // in
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            mat[i][j] = inf;
            vis[i][j] = 0;
        }
    }
    mat[x][y] = 0;

    // solve
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    int round = 0;
    while(!q.empty()){
        int size = q.size();
        round += 1;
        while(size-- > 0){
            pair<int, int> tp = q.front();q.pop();
            int tx = tp.first, ty = tp.second;
            for(auto p : dir){
                int nx = tx + p[0], ny = ty + p[1];
                if(nx > 0 && nx <= n && ny > 0 && ny <= m && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    mat[nx][ny] = round;
                    q.push({nx, ny});
                }
            }
        }
    }

    // out
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mat[i][j] == inf){
                mat[i][j] = -1;
            }
            printf("%-5d", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}