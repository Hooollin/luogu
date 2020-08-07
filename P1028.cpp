#include <bits/stdc++.h>

using namespace std;

int ans = 1;

void dfs(int n){
	for(int i = 1; i <= n / 2; i++){
		ans += 1;
		dfs(i);
	}
}

int main(){
	int n;
	cin >> n;
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i / 2; j++){
			dp[i] += dp[j];
		}
	}
	cout << dp[n] << endl;
	return 0;
}