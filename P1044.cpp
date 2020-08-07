#include <bits/stdc++.h>

using namespace std;

int main(){
	stack<int> s;
	int n;
	cin >> n;
	int f[n + 1];
	memset(f, 0, sizeof f);
	f[0] = 1, f[1] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < i; j++){
			f[i] += f[j] * f[i - j - 1];
		}
	}
	cout << f[n] << endl;
	return 0;
}