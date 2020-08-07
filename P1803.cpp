#include <bits/stdc++.h>

using namespace std;

struct game{
	int start;
	int end;
};

game games[(int)1e6 + 1];

bool cmp(game &a, game &b){
	return a.end < b.end;
}

void greedy(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		game g;
		cin >> g.start >> g.end;
		games[i] = g;
	}
	sort(games, games + n, cmp);
	int ans = 1;
	int end = games[0].end;
	for(int i = 1; i < n; i++){
		if(end <= games[i].start){
			end = games[i].end;
			ans += 1;
		}
	}
	cout << ans << endl;
}

int main(){
	return 0;
}