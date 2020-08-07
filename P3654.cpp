#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e2 + 1;
char mat[maxn][maxn];

bool validR(int i, int s, int e){
	while(s <= e){
		if(mat[i][s] != '.'){
			return false;
		}
		s += 1;
	}
	return true;
}

bool validC(int i, int s, int e){
	while(s <= e){
		if(mat[s][i] != '.'){
			return false;
		}
		s += 1;
	}
	return true;
}

int main(){
	int R, C, K;
	int ans = 0;
	cin >> R >> C >> K;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> mat[i][j];
		}
	}

	for(int i = 0; i < R; i++){
		for(int j = 0; j + K <= C; j++){
			ans += validR(i, j, j + K - 1);
		}
	}

	for(int i = 0; i < C; i++){
		for(int j = 0; j + K <= R; j++){
			ans += validC(i, j, j + K - 1);
		}
	}
	if(K == 1){
		cout << ans / 2 << endl;
	}else cout << ans << endl;
	return 0;
}