//
// Dijkstra.cpp
// Created by Hollin on 7/27/2020
//

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 1;
bool vis[maxn];
int dis[maxn];
int mat[maxn][maxn];

void dijkstra(int v, int n){
    dis[v] = 0;
    for(int i = 0; i < n; i++){
        int k = -1;
        for(int j = 0; j < n; j++){
            if(!vis[j] && (k == -1 || dis[k] > dis[j])){
                k = j;
            }
        }
        vis[k] = 1;
        for(int j = 0; j < n; j++){
            if(!vis[j] && dis[k] + mat[k][j] < dis[j]){
                dis[j] = dis[k] + mat[k][j];
            }
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    memset(vis, 0, sizeof(bool) * n);
    memset(dis, 10000, sizeof(int) * n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = 10000;
            if(i == j){
                mat[i][j] = 0;
            }
        }
    }
    while(e-- > 0){
        int x, y, w;
        cin >> x >> y >> w;
        mat[x][y] = w;
        mat[y][x] = w;
    }
    dijkstra(0, n);
    for(int i = 0; i < n; i++){
        cout << dis[i] << " ";
    }
    return 0;
}
