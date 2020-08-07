#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e4 + 1;
int arr[maxn];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < m; i++){
		next_permutation(arr, arr + n);
	}
	for(int i = 0; i < n; i++){
		printf("%d", arr[i]);
		if(i < n){
			printf(" ");
		}
	}
	return 0;
}