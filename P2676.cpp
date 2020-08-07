#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, b;
	cin >> n >> b;
	int height[n];
	for(int i = 0; i < n; i++){
		cin >> height[i];
	}
	sort(height, height + n);
	int curr = 0;
	int cnt = 0;
	for(int i = n - 1; i >= 0; i--){
		curr += height[i];
		cnt += 1;
		if(curr >= b){
			break;
		}
	}
	cout << cnt;
	return 0;
}