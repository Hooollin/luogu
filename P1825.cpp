//
// P1825.cpp 
// Created by Hollin on 8/4/2020
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 301;
char mat[maxn][maxn];
bool vis[maxn][maxn];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
vector<vector<pair<int, int>>> teleports(26, vector<pair<int, int>>(0));

int main(){
    int N, M;
    cin >> N >> M;
    memset(vis, 0, sizeof vis);
    pair<int, int> start, end;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> mat[i][j];
            if(isalpha(mat[i][j])){
                teleports[mat[i][j] - 'A'].push_back({i, j});
            }else if(mat[i][j] == '@'){
                start.first = i;
                start.second = j;
            }else if(mat[i][j] == '='){
                end.first = i;
                end.second = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(start);
    int ans = 0;
    bool found = false;
    vis[start.first][start.second] = true;
    while(!q.empty() && !found){
        ans += 1;
        int size = q.size();
        while(size-- > 0){
            pair<int, int> now = q.front();q.pop();
            //cout << now.first << " " << now.second << endl;
            for(int i = 0; i < 4; i++){
                int nx = dx[i] + now.first, ny = dy[i] + now.second;
                if(nx < 0 || ny < 0 || nx >= N || ny >= M || mat[nx][ny] == '#' || vis[nx][ny]){
                    continue;
                }
                if(nx == end.first && ny == end.second){
                    found = true;
                }
                if(isalpha(mat[nx][ny])){
                    for(auto p : teleports[mat[nx][ny] - 'A']){
                        if(p.first == nx && p.second == ny){
                            continue;
                        }else{
                            q.push({p.first, p.second});
                        }
                    }
                }else{
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}