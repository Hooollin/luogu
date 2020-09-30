#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int p[maxn];

vector<vector<int>> g(maxn, vector<int>());
bool vis[maxn];

void dfs(int now, int val){
	if(vis[now]) return;
	vis[now] = 1;
	p[now] = val;
	for(auto nxt : g[now]){
		dfs(nxt, val);
	}
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
		g[y].push_back(x);
	}
	for(int i = n; i >= 1; i--){
		dfs(i, i);
	}
	for(int i = 1; i <= n; i++){
		cout << p[i] << " ";
	}
	return 0;
}
