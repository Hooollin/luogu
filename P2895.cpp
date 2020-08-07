//
// P2895.cpp 
// Created by Hollin on 7/29/2020
//

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e2 + 5;
bool last[maxn][maxn];
bool now[maxn][maxn];
bool vis[maxn][maxn];
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool isNowSafe(int x, int y){
    return !now[x][y];
}
bool isLastSafe(int x, int y){
    return !last[x][y];
}

int main(){
    int M;
    cin >> M;
    vector<vector<pair<int, int>>> time(1000, vector<pair<int, int>>(0));
    for(int i = 0; i < maxn; i++){
        for(int  j = 0; j < maxn; j++){
            last[i][j] = 0;
            now[i][j] = 0;
            vis[i][j] = 0;
        }
    }
    while(M-- > 0){
        int t, x, y;
        cin >> x >> y >> t;
        time[t].push_back({x, y});
        last[x][y] = true;
        for(auto p : dirs){
            int nx = p[0] + x, ny = p[1] + y;
            if(nx >= 0 && ny >= 0 && nx < maxn && ny < maxn){
                last[nx][ny] = true;
            }
        }
    }
    queue<pair<int, int>> q;
    int currx = 0, curry = 0;
    q.push({currx, curry});
    vis[currx][curry] = 1;
    int ans = 0;
    bool found = false;
    while(!q.empty()){
        while(time[ans].size() > 0){
            pair<int, int> loc = time[ans][time[ans].size() - 1]; time[ans].pop_back();
            int x = loc.first, y = loc.second;
            now[x][y] = true;
            for(auto p : dirs){
                int nx = p[0] + x, ny = p[1] + y;
                if(nx >= 0 && ny >= 0 && nx < maxn && ny < maxn){
                    now[nx][ny] = true;
                }
            }
        }
        int size = q.size();
        while(size-- > 0){
            pair<int, int> u = q.front();q.pop();
            int x = u.first, y = u.second;
            if(isLastSafe(x, y)){
                found = true;
                break;
            }
            if(!isNowSafe(x, y)){
                continue;
            }
            for(auto p : dirs){
                int nx = x + p[0], ny = y + p[1];
                if(nx < 0 || nx >= maxn || ny < 0 || ny >= maxn || vis[nx][ny]){
                    continue;
                }
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        if(found){
            break;
        }
        ans += 1;
    }
    ans = found ? ans : -1;
    cout << ans << endl;
    //for(int i = 0; i < 10; i++){
    //    for(int j = 0; j < 10; j++){
    //        cout << last[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << endl;
    //for(int i = 0; i < 10; i++){
    //    for(int j = 0; j < 10; j++){
    //        cout << now[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    return 0;
}