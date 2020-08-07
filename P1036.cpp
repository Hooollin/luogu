#include <bits/stdc++.h>
using namespace std;

int arr[21];
bool vis[21];
int ans = 0;
bool isPrime(int s){
	if(s == 1){
		return true;
	}
	for(int i = 2; i < s; i++){
		if(s % i == 0){
			return false;
		}
	}
	return true;
}

void dfs(int i, int n, int cnt, int k, int s){
	if(cnt == k){
		if(isPrime(s)){
			ans += 1;
		}
		return;
	}
	for(; i < n; i++){
		if(vis[i]){
			continue;
		}
		vis[i] = 1;
		dfs(i + 1, n, cnt + 1, k, s + arr[i]);
		vis[i] = false;
	}
}

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	dfs(0, n, 0, k, 0);
	cout << ans << endl;
	return 0;
}