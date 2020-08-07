#include <bits/stdc++.h>
using namespace std;
int mem[1001][1001];

int main(){
	int kases;
	cin >> kases;
	memset(mem, 0, sizeof mem);
	for(int i = 1; i <= 1000; i++){
		for(int j = 1; j <= 1000; j++){
			if(__gcd(i, j) == 1){
				mem[i][j] += 1;
			}
			int t = 0;
			if(i > 1){
				t = max(mem[i - 1][j], t);
			}
			if(j > 1){
				t = max(mem[i][j - 1], t);
			}
			mem[i][j] += t;
		}
	}
	for(int _ = 0; _ < kases; _++){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", mem[a][b]);
	}
	return 0;
}