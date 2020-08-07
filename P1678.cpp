#include <bits/stdc++.h>
using namespace std;

int main(){
	int m, n;
	cin >> m >> n;
	int arr[m];
	for(int i = 0; i < m; i++){
		cin >> arr[i];
	}
	sort(arr, arr + m);
	int ans = 0;
	while(n-- > 0){
		int score;
		cin >> score;
		if(score >= arr[0] && score <= arr[m - 1]){
			int low = lower_bound(arr, arr + m, score) - arr;
			if(low > 0){
				ans += min(arr[low] - score, score - arr[low - 1]);
			}else{
				ans += arr[low] - score;
			}
		}else if(score < arr[0]){
			ans += arr[0] - score;
		}else{
			ans += score - arr[m - 1];
		}
	}
	cout << ans << endl;
	return 0;
}