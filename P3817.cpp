#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int arr[n];
	long long ans = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if(arr[i] > m){
			ans += arr[i] - m;
			arr[i] = m;
		}
	}
	for(int i = 1; i < n; i++){
		if(arr[i] + arr[i - 1] > m){
			ans += arr[i] + arr[i - 1] - m;
			arr[i] = m - arr[i - 1];
		}
	}
	cout << ans;
	return 0;
}