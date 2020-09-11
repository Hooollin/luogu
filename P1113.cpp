#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int ind[maxn] = {0};
int len[maxn] = {0};
int _time[maxn] = {0};
vector<vector<int>> graph;


int main(){
	int n;
	cin >> n;
	graph.resize(n + 1);
	for(int i = 1; i <= n; i++){
		int x, y, w;
		cin >> y >> w;
		len[y] = w;
		while(cin >> x){
			if(x == 0){
				break;
			}
			graph[x].push_back(y);
			ind[y] += 1;
		}
	}
	queue<int> now;
	for(int i = 1; i <= n; i++){
		if(ind[i] == 0){
			now.push(i);
			_time[i] = len[i];
		}
	}
	int ans = 0;
	while(!now.empty()){
		int x = now.front(); now.pop();
		int t = len[x];
		for(int i = 0; i < graph[x].size(); i++){
			int y = graph[x][i];
			_time[y] = max(_time[y], len[y] + _time[x]);
			ind[y] -= 1;
			if(ind[y] == 0){
				now.push(y);
			}
			ans = max(_time[y], ans);
		}
	}
	cout << ans;
	return 0;
}
