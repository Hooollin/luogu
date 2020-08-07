#include <bits/stdc++.h>

using namespace std;
string front[6] = {"oooo****--", "ooo--***o*", "ooo*o**--*", "o--*o**oo*", "o*o*o*--o*", "--o*o*o*o*"};
void dfs(string now, int n){
	if(n == 0){
		return;
	}
	if(n == 4){
		for(int i = 0; i < 6; i++){
			cout << front[i] << now.substr(front[i].size(), now.size()) << endl;
		}
		return;
	}
	cout << now << endl;
	swap(now[n - 1], now[2 * n + 1]);
	swap(now[n], now[2 * n]);
	swap(now[2 * n + 1], now[2 * n]);
	cout << now << endl;
	swap(now[n - 1], now[2 * n - 1]);
	swap(now[n], now[2 * n - 2]);
	dfs(now, n - 1);
}

int main(){
	int n;
	cin >> n;
	string now;
	for(int i = 0; i < n; i++){
		now += "o";
	}
	for(int i = 0; i < n; i++){
		now += "*";
	}
	now += "--";
	dfs(now, n);
	return 0;
}