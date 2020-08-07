#include <bits/stdc++.h>

using namespace std;
void dfs(int n){
	if(n == 1){
		cout << "2(0)";
		return;
	}
	int k = 1, remain = 0;
	while(pow(2, k + 1) <= n){
		k += 1;
	}
	remain = n - pow(2, k);
	if(k > 1){
		cout << "2(";
		dfs(k);
		cout << ")";
	}else{
		cout << "2";
	}
	if(remain > 0){
		cout << "+";
		dfs(remain);
	}
}

int main(){
	int n;
	cin >> n;
	dfs(n);
	return 0;
}