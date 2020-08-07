#include <iostream>

using namespace std;

const int maxn = 1000;

int mat[maxn][maxn];

void swap(int x1, int y1, int x2, int y2){
	int t = mat[x1][y1];
	mat[x1][y1] = mat[x2][y2];
	mat[x2][y2] = t;
}

void rotate(int x, int y, int s, int z){
	for(int i = 0; i < s; i++){
		for(int j = i + 1; j < s; j++){
			swap(i + x, j + y, j + x, i + y);
		}
	}
	if(z == 0){
		int start = y, end = y + s - 1;
		while(start < end){
			for(int i = 0; i < s; i++){
				swap(x + i, start, x + i, end);
			}
			start += 1;
			end -= 1;
		}
	}else{
		int start = x, end = x + s - 1;
		while(start < end){
			for(int i = 0; i < s; i++){
				swap(start, y + i, end, y + i);
			}
			start += 1;
			end -= 1;
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	int cnt = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			mat[i][j] = cnt++;
		}
	}
	while(m-- > 0){
		int x, y, r, z;
		cin >> x >> y >> r >> z;
		int startx = x - r - 1, starty = y - r - 1;
		rotate(startx, starty, 2 * r + 1, z);

	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

