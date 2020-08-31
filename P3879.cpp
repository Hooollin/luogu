#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, mm;
	cin >> n;
	map<string, vector<int>> m;
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 0; j < k; j++){
			string word;
			cin >> word;
			if(m.find(word) == m.end()){
				m[word] = vector<int>();
			}
			m[word].push_back(i);
		}
	}
	cin >> mm;
	while(mm-- > 0){
		string word;
		cin >> word;
		if(m.find(word) == m.end()){
			cout << endl;
		}else{
			set<int> seen;
			for(auto p : m[word]){
				if(seen.find(p) == seen.end()){
					seen.insert(p);
					cout << p << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}
