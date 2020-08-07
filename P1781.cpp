#include <bits/stdc++.h>
using namespace std;

bool cmp(string &a, string &b){
	if(a.size() != b.size()){
		return a.size() < b.size();
	}
	return a < b;
}

int main(){
	int n;
	cin >> n;
	string score[n];
	map<int, string> m;
	for(int i = 0; i < n; i++){
		cin >> score[i];
		m[i + 1] = score[i];
	}
	sort(score, score + n, cmp);
	for(auto i : m){
		if(i.second == score[n - 1]){
			cout << i.first << endl << i.second;
			break;
		}
	}
	return 0;
}