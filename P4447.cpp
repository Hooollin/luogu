#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	map<int, priority_queue<int, vector<int>, greater<int>>> m;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for(int i = 0; i < n; i++){
		if(m.find(arr[i] - 1) == m.end()){
			m[arr[i]] = priority_queue<int, vector<int>, greater<int>>();
			m[arr[i]].push(1);
		}else{
			if(m[arr[i] - 1].size() > 0){
				int k = m[arr[i] - 1].top();m[arr[i] - 1].pop();
				if(m.find(arr[i]) == m.end()){
					m[arr[i]] = priority_queue<int, vector<int>, greater<int>>();
				}
				m[arr[i]].push(k + 1);
			}else{
				m[arr[i]].push(1);
			}
		}
	}
	int ans = 100001;
	for(auto i : m){
		if(i.second.size() > 0) ans = min(ans, i.second.top());
	}
	cout << ans << endl;
	return 0;
}