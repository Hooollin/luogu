#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 1;

int p[maxn];
int cnt = 0;
map<string, int> m;
map<int, string> m1;

int get(string &s){
	if(m.find(s) != m.end()){
		return m[s];
	}
	m[s] = ++cnt;
	m1[cnt] = s;
	return m[s];
}

int find(int x){
	if(p[x] == x){
		return x;
	}
	return p[x] = find(p[x]);
}


void uni(int x, int y){
	x = find(x), y = find(y);
	p[y] = x;
}

int main(){
	for(int i = 1; i <= maxn - 1; i++){
		p[i] = i;
	}
	string s;
	int fa = -1;
	while(cin >> s){
		char k = s[0];
		s = s.substr(1, s.size() - 1);
		if(k == '$'){
			break;
		}else if(k == '#'){
			fa = get(s);
		}else if(k == '+'){
			uni(fa, get(s));
		}else{
			cout << s << " " << m1[find(get(s))] << endl;
		}
	}
	return 0;
}
