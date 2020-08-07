#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, C;
	cin >> N >> C;
	map<long, long> m;
	for(int i = 0; i < N; i++){
		long long t;
		cin >> t;
		if(m.find(t) == m.end()){
			m[t] = 0;
		}
		m[t] += 1;
	}
	long long ans = 0;
	for(auto i : m){
		int key = i.first - C;
		if(m.find(key) != m.end()){
			ans += m[key] * (i.second);
		}
	}
	cout << ans << endl;
	return 0;
}