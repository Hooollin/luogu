#include <bits/stdc++.h>
using namespace std;

struct apple{
	int x, y;
};



bool cmp(apple &a, apple &b){
	if(a.y != b.y){
		return a.y < b.y;
	}
	return a.x < b.x;
}

apple arr[5001];

int main(){
	int n, s;
	cin >> n >> s;
	int a, b;
	cin >> a >> b;
	int maxh = a + b;
	for(int i = 0; i < n; i++){
		apple t;
		cin >> t.x >> t.y;
		if(t.x <= maxh && t.y <= s){
			arr[i] = t;
		}else{
			i -= 1;
			n -= 1;
		}
	}
	sort(arr, arr + n, cmp);
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(s >= arr[i].y){
			ans += 1;
			s -= arr[i].y;
		}else{
			break;
		}
	}
	cout << ans << endl;
	return 0;
}