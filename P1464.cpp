#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll f[21][21][21];

ll w(ll a, ll b, ll c){
	if(a <= 0 || b <= 0 || c <= 0){
		return 1;
	}
	if(a > 20 || b > 20 || c > 20){
		return w(20, 20, 20);
	}
	if(f[a][b][c] != -1){
		return f[a][b][c];
	}
	if(a < b && b < c){
		f[a][b][c] = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
		return f[a][b][c];
	}
	f[a][b][c] = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	return f[a][b][c];
}

int main(){
	memset(f, -1, sizeof(f));
	string line;
	while(getline(cin, line)){
		stringstream ss(line);
		int a, b, c;
		ss >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1){
			return 0;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
	}
	return 0;
}