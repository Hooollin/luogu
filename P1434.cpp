#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 105, maxm = 105;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int mp[maxn][maxm];
int f[maxn][maxm];

int dfs(int x, int y, int n, int m){
    if(x >= n || y >= m || x < 0 || y < 0){
        return -1;
    }
    if(f[x][y] != -1){
        return f[x][y];
    }
    f[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(mp[x][y] <= mp[nx][ny]){
            continue;
        }
        f[x][y] = max(f[x][y], 1 + dfs(nx, ny, n, m));
    }
    return f[x][y];
}

int main(){
    memset(f, -1, sizeof(f));
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mp[i][j];
        }       
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(f[i][j] == -1){
                ans = max(dfs(i, j, n, m), ans);
            }
        }
    }
    cout << ans << endl;
    return 0;
}