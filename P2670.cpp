#include <iostream>
using namespace std;

const int maxn = 10001, maxm = 10001;
char map[maxn][maxm];

int cnt(int i, int j){
	int ans = 0;
	int x1 = i - 1, x2 = i + 1, y = j - 1;
	while(y <= j + 1){
		if(map[x1][y] == '*'){
			ans += 1;
		}
		if(map[x2][y] == '*'){
			ans += 1;
		}
		y += 1;
	}
	ans += map[i][j - 1] == '*' ? 1 : 0;
	ans += map[i][j + 1] == '*' ? 1 : 0;
	return ans;
}

void solve(int n, int m){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(map[i][j] == '?'){
				map[i][j] = '0' + cnt(i, j);
			}
			cout << map[i][j];
		}
		cout << endl;
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	string line;
	int i = 1;
	while(cin >> line){
		for(int k = 0; k < line.size(); k++){
			map[i][k + 1] = line[k];
		}
		i += 1;
	}
	solve(n, m);
}
