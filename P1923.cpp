#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
const int maxn = 5e6 + 2;
int arr[maxn];

void swap(int i, int j){
	int t = arr[j];
	arr[j] = arr[i];
	arr[i] = t;
}
int partition(int l, int r){
	int key = arr[(l + r) / 2];
	swap(l, (l + r) / 2);
	int i = l, j = r;
	while(i < j){
		while(i < j && arr[j] > key){
			j -= 1;
		}
		arr[i] = arr[j];
		while(i < j && arr[i] <= key){
			i += 1;
		}
		arr[j] = arr[i];
	}
	arr[i] = key;
	return i;
}

void solve(int l, int r, int k){
	if(l <= r){
		int loc = partition(l, r);
		if(loc == k){
			cout << arr[loc];
			return;
		}
		if(loc > k - 1){
			solve(l, loc - 1, k);
		}else{
			solve(loc + 1, r, k);
		}
	}
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", arr + i);
	}
	solve(0, n - 1, k);
	return 0;
}