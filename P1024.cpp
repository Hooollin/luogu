#include <bits/stdc++.h>
using namespace std;

double f(double last, int a, int b, int c, int d){
	return a * last * last * last + b * last * last + c * last + d;
}

double bs(int last, int now){
	double flast = f(last);
	double fnow = f(now);
	while(flast * fnow){

	}
}
int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	double start = -100, end = 100;
	double last = start;
	double flast = f(last, a, b, c, d);
	for(double now = start + 1; now <= end; now++){
		int fnow = f(now, a, b, c, d);
		if(fnow * flast < 0){
			printf("%.2lf", bs(last, now));
			last = now;
			flast = fnow;
		}
	}
}