#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int cnt = m * 1.5;
	int scores[n];
	map<int, int> vis;
	map<int, int> nvis;
	map<int, vector<int> > map;
	for(int i = 0; i < n; i++){
		int number, score;
		cin >> number >> score;
		map[score].push_back(number);
		scores[i] = score;
	}
	sort(scores, scores + n);
	int cc = 0;
	int ms = 10000;
	for(int i = n - 1; cc < cnt && i >= 0; i--){
		if(vis.find(scores[i]) != vis.end()){
			continue;
		}
		cc += map[scores[i]].size();
		ms = min(ms, scores[i]);
		vis[scores[i]] = 1;
	}
	cout << ms << " " << cc << endl;
	int t = cnt;
	for(int i = n - 1; t > 0 && i >= 0; i--){
		int s = scores[i];
		if(nvis.find(s) != nvis.end()){
			continue;
		}
		vector<int> tt = map[s];
		sort(tt.begin(), tt.end());
		t -= tt.size();
		for(int j = 0; j < tt.size(); j++){
			cout <<tt[j] << " " << s << endl;
		}
		nvis[s] = 1;
	}
	return 0;
}