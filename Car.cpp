#include <bits/stdc++.h>
using namespace std;

bool valid(vector<int> cars, int m){
	int min1 = 100000, min1idx = -1;
	int min2 = 100000, min2idx = -1;
	for(int i = 0; i < cars.size(); i++){
		if(cars[i] < min1){
			min1 = cars[i];
			min1idx	= i;
		}
	}
	for(int i = 0; i < cars.size(); i++){
		if(i == min1idx){
			continue;
		}
		if(cars[i] < min2){
			min2 = cars[i];
			min2idx = i;
		}
	}
	int sum = 0;
	for(int i = 0; i < cars.size(); i++){
		sum += i;
	}
	return (m + min1 + min2) >= sum;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T-- > 0){
		int n;
		scanf("%d", &n);
		vector<int> cars(10);
		for(int i = 0; i < n; i++){
			string t;
			cin >> t;
			cars[t[t.size() - 1] - '0'] += 1;
		}
		int s = 1, e = n;
		int ans = 1;
		while(s <= e){
			int mid = (s + e) / 2;
			if(valid(cars, mid)){
				ans = e;
				e = e - 1;
			}else{
				s = s + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}