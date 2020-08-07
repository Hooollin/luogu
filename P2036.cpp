#include <bits/stdc++.h>
using namespace std;
int dfs(int taste[][2], int i, int k, int cs, int cw, bool vis[], int N){
	if(i == k){
		return abs(cs - cw);
	}
	int ans = 0x3f3f3f3f;
	for(int j = 0; j < N; j++){
		if(vis[j]) continue;
		vis[j] = true;
		ans = min(dfs(taste, i + 1, k, cs == 0 ? taste[j][0] : cs * taste[j][0], cw + taste[j][1], vis, N), ans);
		vis[j] = false;
	}
	return ans;
}

int main(){
	int N;
	cin >> N;
	int taste[N][2];
	for(int i = 0; i < N; i++){
		cin >> taste[i][0] >> taste[i][1];
	}
	int ans = 0x3f3f3f3f;
	for(int i = 1; i <= N; i++){
		bool vis[N];
		memset(vis, 0, sizeof vis);
		ans = min(dfs(taste, 0, i, 0, 0, vis, N), ans);
	}
	cout << ans << endl;
	return 0;
}
