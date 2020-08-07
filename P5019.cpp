#include <bits/stdc++.h>
using namespace std;

int dfs(int arr[], int start, int end){
	if(start > end){
		return 0;
	}
	if(start == end){
		return arr[start];
	}
	int mini = start;
	for(int i = start + 1; i <= end; i++){
		if(arr[mini] > arr[i]){
			mini = i;
		}
	}
	for(int i = start; i < mini; i++){
		arr[i] -= arr[mini];
	}
	for(int i = mini + 1; i <= end; i++){
		arr[i] -= arr[mini];
	}
	return arr[mini] + dfs(arr, start, mini - 1) + dfs(arr, mini + 1, end);
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << dfs(arr, 0, n - 1) << endl;
	return 0;
}