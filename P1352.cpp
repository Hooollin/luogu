#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int h[maxn];
vector<int> son[maxn];
int f[maxn][2];
int ind[maxn];

void dp(int now){
	for(auto s : son[now]){
		dp(s);
		f[now][0] += max(f[s][0], f[s][1]);
		f[now][1] += f[s][0];
	}
	f[now][1] += h[now];
}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> h[i];
		ind[i] = 0;
	}
	for(int i = 1; i < n; i++){
		int k, l;
		cin >> k >> l;
		son[l].push_back(k);
		ind[k] += 1;
	}
	int root = 1;
	for(int i = 1; i <= n; i++){
		if(ind[i] == 0){
			root = i;
			break;
		}
	}
	memset(f, 0, sizeof(f));
	dp(root);
	//cout << root << endl;
	cout << max(f[root][0], f[root][1]) << endl;
	return 0;
}
