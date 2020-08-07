#include <bits/stdc++.h>

using namespace std;

struct milk{
	int p;
	int a;
};

bool cmp(milk &a, milk &b){
	return a.p < b.p;
}

int main(){
	int n, m;
	cin >> n >> m;
	milk arr[m];
	for(int i = 0; i < m; i++){
		milk t;
		cin >> t.p >> t.a;
		arr[i] = t;
	}
	sort(arr, arr + m, cmp);
	int ans = 0;
	for(int i = 0; i < m; i++){
		if(n > arr[i].a){
			ans += arr[i].p * arr[i]. a;
			n -= arr[i].a;
		}else{
			ans += arr[i].p * n;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}