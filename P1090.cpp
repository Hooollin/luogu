#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 1;


int main(){
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		q.push(t);
	}
	int ans = 0;
	while(q.size() > 1){
		int u1 = q.top();q.pop();
		int u2 = q.top();q.pop();
		int curr = u1 + u2;
		q.push(u1 + u2);
		ans += curr;
	}
	cout << ans << endl;
	return 0;
}