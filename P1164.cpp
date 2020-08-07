#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, M;
	cin >> N >> M;
	if(N == 0){
		cout << 0 << endl;
	}
	int p[N];
	for(int i = 0; i < N; i++){
		cin >> p[i];
	}
	int f[N + 1][M + 1];
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(p[i - 1] == j){
				f[i][j] = f[i - 1][j] + 1;
			}else if(p[i - 1] > j){
				f[i][j] = f[i - 1][j];
			}else{
				f[i][j] = f[i - 1][j] + f[i - 1][j - p[i - 1]];
			}
		}
	}
	cout << f[N][M] << endl;
	return 0;
}