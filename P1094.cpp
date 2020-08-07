#include <bits/stdc++.h>

using namespace std;

int main(){
	int w, n;
	cin >> w >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int i = 0, j = n - 1;
	int ans = 0;
	while(i < j){
		if(arr[i] + arr[j] <= w){
			i += 1;
			j -= 1;
			ans += 1;
		}else{
			j -= 1;
			ans += 1;
		}
	}
	ans += i == j;
	cout << ans << endl;
	return 0;
}