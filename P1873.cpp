#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 1e6 + 1;

int arr[maxn];

long long cal(int N, int h){
	LL sum = 0;
	for(int i = 0; i < N; i++){
		if(h <= arr[i]){
			sum += arr[i] - h;
		}
	}
	return sum;
}

int bs(int start, int end, int N, LL M){
	int ans = start;
	while(start <= end){
		int mid = start + (end - start) / 2;
		LL sum = cal(N, mid);
		if(sum >= M){
			ans = mid;
			start = mid + 1;
		}else{
			end = mid - 1;
		}
	}
	return ans;
}

int main(){
	int N;
	LL  M;
	cin >> N >> M;
	int maxv = 0, minv = 1e6 + 1;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		maxv = max(maxv, arr[i]);
		minv = min(minv, arr[i]);
	}
	cout << bs(minv, maxv, N, M);
	return 0;
}