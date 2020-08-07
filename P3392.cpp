#include <bits/stdc++.h>
using namespace std;

char mat[51][51];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
		}
	}
	int ans = 0;
	int rans = 0x3f3f3f3f;
	for(int j = 1; j < n - 1; j++){
		for(int l = j + 1; l < n; l++){
			int cost = 0;
			for(int k = 0; k < j; k++){
				for(int r = 0; r < m; r++){
					cost += mat[k][r] != 'W';
				}
			}
			for(int k = j; k < l; k++){
				for(int r = 0; r < m; r++){
					cost += mat[k][r] != 'B';
				}
			}
			for(int k = l; k < n; k++){
				for(int r = 0; r < m; r++){
					cost += mat[k][r] != 'R';
				}
			}
			rans = min(rans, ans + cost);
		}
	}
		
	cout << rans << endl;
	return 0;
}