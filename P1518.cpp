#include <iostream>
#include <string>
#include <utility>
using namespace std;
char mat[10][10];
int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool meet(pair<int, int> cow, pair<int, int> farm){
	//cout << cow.first << " " << cow.second << "|" << farm.first << " " << farm.second << endl;
	if(cow.first == farm.first && cow.second == farm.second){
		return true;
	}
	return false;
}

void update(pair<int, int> &target, int &dir){
	int x = target.first, y = target.second;
	int nx = x + dirs[dir][0], ny = y + dirs[dir][1];
	if(nx < 0 || nx >= 10 || ny < 0 || ny >= 10 || mat[nx][ny] == '*'){
		dir = (dir + 1) % 4;
	}else{
		target.first = nx, target.second = ny;
	}
}

int main(){
	string line;
	int cnt = 0;
	pair<int, int> cow, farm;
	while(cin >> line){
		for(int i = 0; i < line.size(); i++){
			mat[cnt][i] = line[i];
			if(mat[cnt][i] == 'C'){
				cow.first = cnt;
				cow.second = i;
			}
			if(mat[cnt][i] == 'F'){
				farm.first = cnt;
				farm.second = i;
			}
		}
		cnt++;
	}
	cnt = 0;
	int cdir = 0, fdir = 0;
	while(cnt < 100000 && !meet(cow, farm)){
		update(cow, cdir);
		update(farm, fdir);
		cnt += 1;
	}
	if(cnt >= 100000){
		cout << 0;
	}else{
		cout << cnt;
	}
	return 0;
}