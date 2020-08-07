#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	map<int, string> names;
	map<int, int> faces;
	for(int _ = 0; _ < n; _++){
		int face;
		string name;
		cin >> face >> name;
		names[_] = name;
		faces[_] = face;
	}
	int curr = 0;
	for(int _ = 0; _ < m; _++){
		int dir, dis;
		cin >> dir >> dis;
		if(faces[curr] == 0){
			if(dir == 0){
				curr = (n + curr - dis) % n;
			}else{
				curr = (curr + dis) % n;
			}
		}else{
			if(dir == 0){
				curr = (curr + dis) % n;
			}else{
				curr = (n + curr - dis) % n;
			}
		}
	}
	cout << names[curr];
	return 0;
}