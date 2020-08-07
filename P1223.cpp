#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;


struct man{
	int time;
	int seq;
};

man mans[MAXN];

bool cmp(man &a, man &b){
	if(a.time != b.time){
		return a.time < b.time;
	}
	return a.seq < b.seq;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		man m;
		cin >> m.time;
		m.seq = i;
		mans[i] = m;
	}
	sort(mans, mans + n, cmp);
	double ans = 0.;
	long long sum = 0;
	for(int i = 0; i < n; i++){
		ans += sum;
		sum += mans[i].time;
		cout << mans[i].seq + 1 << " ";
	}
	cout << endl;
	printf("%.2lf", ans / n);
	return 0;
}

