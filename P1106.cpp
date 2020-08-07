#include <bits/stdc++.h>
using namespace std;
const int N = 251;
int num[N];

void dfs(int start, int n, int &k){
	if(start == n){
		return;
	}
	if(k == 0){
		return;
	}
	int mini = start;
	for(int i = start; i <= start + k; i++){
		if(num[i] < num[mini]){
			mini = i;
		}
	}
	for(int i = start; i < mini && k > 0; i++){
		num[i] = -1;
		k -= 1;
	}
	dfs(mini + 1, n, k);
	if(k > 0){
		cout << k << endl;
		num[mini] = -1;
		k -= 1;
	}
}

int main(){
	int n;
	string nn;
	int k;
	cin >> nn >> k;
	n = nn.size();
	for(int i = 0; i < n; i++){
		num[i] = nn[i] - '0';
	}
	if(k >= n){
		cout << 0 << endl;
	}else{
		dfs(0, n, k);
		bool hasNonZero = false;
		bool allZero = true;
		for(int i = 0; i < n; i++){
			if(num[i] != -1){
				if(num[i] != 0){
					hasNonZero = true;
					allZero = false;
				}
				if(hasNonZero) cout << num[i];
			}
		}
		if(allZero){
			cout << 0 << endl;
		}
	}
	return 0;
}