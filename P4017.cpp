#include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;
const int maxm = 5e6 + 5;
const int mod = 80112002;

long long dist[maxn];

vector<vector<int>> g(maxn);
int ind[maxn];

int main(){
	memset(dist, 0, sizeof(dist));
	memset(ind, 0, sizeof(ind));
	int n, m;
	cin >> n >> m;
	while(m-- > 0){
		int x, y;
		cin >> x >> y;	
		g[x].push_back(y);
		ind[y] += 1;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(ind[i] == 0){
			q.push(i);
			dist[i] = 1;
		}
	}
	while(!q.empty()){
		int now = q.front(); q.pop();
		for(auto next : g[now]){
			ind[next] -= 1;
			dist[next] = (dist[now] + dist[next]) % mod;
			if(ind[next] == 0) q.push(next);
		}
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		if(g[i].size() == 0){
			ans = (ans + dist[i]) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}
