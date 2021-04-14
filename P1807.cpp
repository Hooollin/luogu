#include <bits/stdc++.h>

using namespace std;

const int maxn = 1550;
const int inf = 1e9 + 5;
vector<vector<pair<int, int>>> graph(maxn, vector<pair<int, int>>());

int ind[maxn];
int dp[maxn];
bool vis[maxn];

int main(){
    memset(dp, 0, sizeof(dp));
    memset(ind, 0, sizeof(ind));
    memset(vis, false, sizeof(vis));
    int n, m;
    cin >> n >> m;
    while(m-- > 0){
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        ind[y] += 1;
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;
    cout << n << endl;
    while(!q.empty()){
        int now = q.front(); q.pop();
        cout << now << endl;
        for(auto next : graph[now]){
            int to = next.first, w = next.second;
            vis[to] = true;
            dp[to] = max(dp[now] + w, dp[to]);
            ind[to] -= 1;
            if(ind[to] == 0){
                q.push(to);
            }
        }
    }
    if(vis[n]){
        cout << dp[n] << endl;
    }else cout << -1 << endl;
    return 0;
}