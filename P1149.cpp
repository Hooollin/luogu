#include <bits/stdc++.h>
using namespace std;

int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ans = 0;

int nums(int i){
	if(i == 0){
		return cost[0];
	}
	int cnt = 0;
	while(i > 0){
		int d = i % 10;
		cnt += cost[d];
		i /= 10;
	}
	return cnt;
}

int main(){
	int n;
	cin >> n;
	n -= 4;
	if(n < 4){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0; i <= 1000; i++){
		for(int j = 0; j <= 1000; j++){
			if(nums(i) + nums(j) + nums(i + j) == n){
				ans += 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}