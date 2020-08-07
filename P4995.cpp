#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n + 1];
	arr[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n + 1);
	int i = 0, j = n;
	long long ans = 0;
	int turn = 0;
	while(i < j){
		if(turn == 0){
			ans += (arr[j] - arr[i]) * (arr[j] - arr[i]);
			i += 1;
			turn = 1;
		}else{
			ans += (arr[j] - arr[i]) * (arr[j] - arr[i]);
			j -= 1;
			turn = 0;
		}
	}
	cout << ans << endl;
	return 0;
}