#include <bits/stdc++.h>

using namespace std;
const int maxn = 100000 + 1;
const int maxk = 100000000 + 1;
int ans = 0;
int tree[maxn];

bool cut(int length, int N, int K){
	for(int i = 0; i < N; i++){
		K -= tree[i] / length;
		if(K <= 0){
			ans = length;
			return true;
		}
	}
	return false;
}

int main(){
	int N, K;
	cin >> N >> K;
	int maxv = 0;
	for(int i = 0; i < N; i++){
		cin >> tree[i];
		maxv = max(tree[i], maxv);
	}
	int minv = 1;
	while(minv <= maxv){
		int mid = (minv + maxv) / 2;
		if(cut(mid, N, K)){
			minv = mid + 1;
		}else{
			maxv = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}