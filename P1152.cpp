#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 1;
int arr[maxn];
int d[maxn];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i < n; i++){
		int diff = abs(arr[i] - arr[i - 1]);
		if(diff >= n){
			cout << "Not jolly" << endl;
			return 0;
		}
		d[diff] += 1;
	}
	bool is = true;
	for(int i = 1; i <= n - 1; i++){
		if(d[i] != 1){
			cout << "Not jolly" << endl;
			is = false;
			break;
		}
	}
	if(is){
		cout << "Jolly" << endl;
	}
	return 0;
}
