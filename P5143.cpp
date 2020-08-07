#include <bits/stdc++.h>

using namespace std;
typedef struct {
	int x, y, z;
}Point;

bool cmp(Point &a, Point &b){
	return a.z > b.z;
}

int main(){
	double ans = 0;
	int n;
	cin >> n;
	vector<Point> p;
	for(int i = 0; i < n; i++){
		Point t;
		cin >> t.x >> t.y >> t.z;
		p.push_back(t);
	}
	sort(p.begin(), p.end(), cmp);
	Point start = p[0];
	for(int i = 1; i < p.size(); i++){
		Point end = p[i];
		ans += sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2) + pow(end.z - start.z, 2));
		start = end;
	}
	printf("%.3f", ans);
	return 0;
}