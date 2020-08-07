#include <iostream>
#include <queue>
#include <map>

using namespace std;

map< int, vector<int> > m;

bool win(int a, int b){
	for(int i = 0; i < m[a].size(); i++){
		if(m[a][i] == b){
			return true;
		}
	}
	return false;
}

bool lose(int a, int b){
	for(int i = 0; i < m[b].size(); i++){
		if(m[b][i] == a){
			return true;
		}
	}
	return false;
}

int main(){
	int N, Na, Nb;
	for(int i = 0; i <= 4; i++){
		m[i] = vector<int>(0);
	}
	m[0].push_back(2);
	m[0].push_back(3);
	m[1].push_back(3);
	m[2].push_back(4);
	m[1].push_back(0);
	m[3].push_back(4);
	m[4].push_back(0);
	m[2].push_back(1);
	m[4].push_back(1);
	m[3].push_back(2);
	cin >> N >> Na >> Nb;
	queue<int> q1, q2;
	for(int i = 0; i < Na; i++){
		int t;
		cin >> t;
		q1.push(t);
	}
	for(int i = 0; i < Nb; i++){
		int t;
		cin >> t;
		q2.push(t);
	}
	int s1 = 0, s2 = 0;
	while(N-- > 0){
		int a = q1.front(), b = q2.front();
		if(win(a, b)){
			s1 += 1;
		}else if(lose(a, b)){
			s2 += 1;
		}
		q1.pop();q2.pop();
		q1.push(a);q2.push(b);
	}
	cout << s1 << " " << s2 << endl;
	return 0;
}
