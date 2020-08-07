#include <bits/stdc++.h>
using namespace std;

int n, k;
void dfs(int now, int cnt, vector<int> ans){
	if(cnt == k){
		for(int i = 0; i < ans.size(); i++){
			printf("%3d", ans[i]);
		}
		cout << endl;
		return;
	}
	for(; now <= n; now++){
		ans.push_back(now);
		dfs(now + 1, cnt + 1, ans);
		ans.pop_back();
	}
}

int main(){
	cin >> n >> k;
	dfs(1, 0, vector<int>());
	return 0;
}