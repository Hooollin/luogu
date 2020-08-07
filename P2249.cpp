#include <bits/stdc++.h>
using namespace std;

int bs(int arr[], int start, int end, int target){
	while(start <= end){
		int mid = start + (start - end) / 2;
		if(arr[mid] == target){
			return mid + 1;
		}else if(arr[mid] > target){
			end = mid - 1;
		}else{
			start = start + 1;
		}
	}
	return -1;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d", arr + i);
	}
	for(int i = 0; i < m; i++){
		int t;
		scanf("%d", &t);
		int ans = lower_bound(arr, arr + n, t);
		if(arr[ans] == t){
			cout << ans << endl;
		}else{
			cout << -1 << endl;
		}
	}
	return 0;
}