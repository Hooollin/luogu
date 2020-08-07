#include <bits/stdc++.h>

using namespace std;

int n, m;
void solvesquare(int n, int m){
	int k = min(n, m);
	int t = 0;
	for(int i = 1; i < k; i++){
		for(int ii = 0; ii < n; ii += k){
			for(int jj = 0; jj < m; jj += k){
				t += 1;
			}
		}
	}
	cout << t << " ";
}

void sloverect(int n, int m){
	int k = max(n, m);
	int t = 0;
	for(int i = )
}
int main(){
	cin >> n >> m;
	solvesquare(n, m);
}