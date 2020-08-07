#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int mat[N][N];


int dfs(int m, int n){
	int ans = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
		}
	}
}
int main(){
	int kases;
	cin >> kases;
	for(int _ = 0; _ < kases; _++){
		int m, n, k;
		scanf("%d%d%d", &m, &n, &k);
		memset(mat, 0, m * n);
		int sum = 0;
		for(int i = 0; i < k; i++){
			int x, y, cnt;
			scanf("%d%d%d", &x, &y, &cnt);
			x -= 1, y -= 1;
			mat[x][y] = cnt;
			sum += cnt;
		}
		if(sum < n * m){
			printf("%d\n", -1);
		}else{
			printf("%d\n", dfs(m, n));
		}
	}
}