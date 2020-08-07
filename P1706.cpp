#include <bits/stdc++.h>

using namespace std;

int n;
bool vis[10];

void dfs(int cnt, vector<int> ans){
	if(cnt == n){
		for(int i = 0; i < ans.size(); i++){
			printf("%5d", ans[i]);
		}
		cout << endl;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]){
			continue;
		}
		ans.push_back(i);
		vis[i] = true;
		dfs(cnt + 1, ans);
		vis[i] = false;
		ans.pop_back();
	}
}
int main(){
	cin >> n;
	memset(vis, 0, sizeof vis);
	dfs(0, vector<int>());
	return 0;
}