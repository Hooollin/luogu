#include <bits/stdc++.h>
using namespace std;

const int maxn = 20000 + 1;

int main(){
	fstream fs("ans", ios::out);
	int T;
	scanf("%d", &T);
	while(T-- > 0){
		vector<int> ans;
		vector<vector<vector<int>>> t(100);
		set<int> infected;
		infected.insert(1);
		ans.push_back(1);
		for(int i = 0; i < t.size(); i++){
			t[i] = vector<vector<int>>(10);
			for(int k = 0; k < 10; k++){
				t[i][k] = vector<int>(0);
			}
		}
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			int s;
			scanf("%d", &s);
			while(s-- > 0){
				int time, p;
				scanf("%d%d", &time, &p);
				time -= 1, p -= 1;
				t[time][p].push_back(i);
			}
		}
		for(int i = 0; i < 100; i++){
			for(int j = 0; j < 10; j++){
				bool hasInfected = false;
				for(int k = 0; k < t[i][j].size(); k++){
					if(infected.find(t[i][j][k]) != infected.end()){
						hasInfected = true;
						break;
					}
				}
				if(hasInfected){
					sort(t[i][j].begin(), t[i][j].end());
					for(int k = 0; k < t[i][j].size(); k++){
						if(infected.find(t[i][j][k]) == infected.end()){
							ans.push_back(t[i][j][k]);
							infected.insert(t[i][j][k]);
						}
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i];
			if(i < ans.size() - 1){
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}