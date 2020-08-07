#include <bits/stdc++.h>

using namespace std;

long long dfs(int x[], int y[], int m, int n){
	if(m == 0){
		return 0;
	}
	int maxi = n;
	double maxa = 1000.;
	for(int i = 0; i < n; i++){
		if(x[i] <= m && y[i] / (x[i] * 1.0) < maxa){
			maxa = y[i] / (x[i] * 1.0);
			maxi = i;
		}
	}
	if(maxi == n){
		long long rev = 100000;
		for(int i = 0; i < n; i++){
			rev = min(rev, (long long)y[i]);
		}
		return rev;
	}
	long long ans = (m / x[maxi]) * y[maxi] + dfs(x, y, m % x[maxi], n);
	return ans;
}
int main(){
	int test;
	cin >> test;
	for(int _ = 0; _ < test; _++){
		int n, m;
		cin >> n >> m;
		int x[n];
		int y[n];
		for(int i = 0; i < n; i++){
			cin >> x[i] >> y[i];
		}
		int ans = 0x3f3f3f3f;
		for(int i = 0; i < n; i++){
			int cnt = m / x[i];
			if(m % x[i] != 0){
				cnt += 1;
			}
			ans = min(y[i] * cnt, ans);
		}
		cout << ans << endl;
	}
	return 0;
}