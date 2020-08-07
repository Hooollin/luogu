#include <bits/stdc++.h>

using namespace std;

bool cmp(string &a, string &b){
	return a + b > b + a;
}
int main(){
	int n;
	cin >> n;
	vector<string> ss;
	for(int i = 0; i < n; i++){
		string t;
		cin >> t;
		ss.push_back(t);
	}
	sort(ss.begin(), ss.end(), cmp);
	for(int i = 0; i < ss.size(); i++){
		cout << ss[i];
	}
	return 0;
}