#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

vector<vector<int>> graph(maxn, vector<int>());

bool vis[maxn];

void dfs(int i){
	vis[i] = true;
	cout << i << " ";
	for(int k = 0; k < graph[i].size(); k++){
		int nxt = graph[i][k];
		if(!vis[nxt]){
			dfs(nxt);
		}
	}
}


void bfs(int i){
	queue<int> q;
	q.push(i);
	vis[i] = true;
	while(!q.empty()){
		int now = q.front(); q.pop();
		cout << now << " ";
		for(int k = 0; k < graph[now].size(); k++){
			int next = graph[now][k];
			if(vis[next]) continue;
			q.push(next);
			vis[next] = true;
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	while(m-- > 0){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
	}
	for(int i = 1; i <= n; i++){
		sort(graph[i].begin(), graph[i].end());
	}
	memset(vis, 0, sizeof(vis));
	dfs(1);
	
	cout << endl;
	memset(vis, 0, sizeof(vis));
	bfs(1);
	return 0;
}
