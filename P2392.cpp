#include <bits/stdc++.h>

using namespace std;
int minv;
int get(vector<int> s, int left, int right, int i){
	if(i == s.size()){
		minv = min(minv, max(left, right));
		return minv;
	}
	int l = get(s, left + s[i], right, i + 1);
	int r = get(s, left, right + s[i], i + 1);
	return min(l, r);
}

int main(){
	vector< vector<int> > ss(4);
	int s[4];
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	for(int k = 0; k < 4; k++){
		for(int i = 0; i < s[k]; i++){
			int t;
			cin >> t;
			ss[k].push_back(t);
		}
	}
	int ans = 0;
	for(int i = 0; i < 4; i++){
		minv = 0x3f3f3f3f;
		ans += get(ss[i], 0, 0, 0);
	}
	cout << ans << endl;
	return 0;
}