#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int p[maxn];

vector<vector<int>> g(maxn, vector<int>());
bool vis[maxn];

int dfs(int now){
	if(vis[now]){
		return p[now];
	}
	vis[now] = true;
	for(auto nxt : g[now]){
		p[now] = max(dfs(nxt), p[nxt]);
	}
	return p[now];
}

int main(){
	int n, m;
	cin >> n >> m;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++){
		p[i] = i;
	}
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]){
			continue;
		}
		dfs(i);
	}
	for(int i = 1; i <= n; i++){
		cout << p[i] << " ";
	}
	return 0;
}
