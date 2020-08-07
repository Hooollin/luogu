#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
int bucket[maxn];
int main(){
	int n;
	cin >> n;
	int cnt = 0;
	memset(bucket, 0, sizeof bucket);
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		bucket[t] += 1;
		if(bucket[t] == 1){
			cnt += 1;
		}
	}
	cout << cnt << endl;
	for(int i = 0; i < maxn; i++){
		if(bucket[i] > 0){
			cout << i << " ";
		}
	}
	return 0;
}