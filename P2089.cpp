#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
void dfs(int k, int sum, int n, string curr){
	if(k == 11){
		if(sum == n){
			ans.push_back(curr);
		}
		return;
	}
	for(int i = 1; i <= 3; i++){
		if(sum + i <= n){
			dfs(k + 1, sum + i, n, curr + to_string(i) + " ");
		}
	}
}

int main(){
	int n;
	cin >> n;
	if(n < 10){
		cout << 0 << endl;
	}else{
		dfs(1, 0, n, "");
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i] << endl;
		}
	}
	return 0;
}