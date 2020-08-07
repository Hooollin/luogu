//
// P1605.cpp 
// Created by Hollin on 7/30/2020
//
#include <bits/stdc++.h>
using namespace std;

const int maxn = 6;
const int inf = 1e9 + 1;
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[maxn][maxn];

int dfs(int x, int y, int ex, int ey, int N, int M){
    if(x == ex && y == ey){
        return 1;
    }
    int ans = 0;
    vis[x][y] = true;
    for(auto p : dirs){
        int nx = x + p[0], ny = y + p[1];
        if(nx <= 0 || nx > N || ny <= 0 || ny > M || vis[nx][ny]){
            continue;
        }
        ans += dfs(nx, ny, ex, ey, N, M);
    }
    vis[x][y] = false;
    return ans;
}

int main(){
    int N, M, T;
    cin >> N >> M >> T;
    memset(vis, 0, sizeof(vis));
    pair<int, int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;
    while(T-- > 0){
        int x, y;
        cin >> x >> y;
        vis[x][y] = true;
    }
    cout << dfs(start.first, start.second, end.first, end.second, N, M) << endl;
    return 0;
}