#include <bits/stdc++.h>

using namespace std;
const int MAXN = 102;
int v[MAXN], w[MAXN];
double avg[MAXN];
int indexs[MAXN];

bool cmp(int &a, int &b){
	return avg[a] > avg[b];
}

int main(){
	int N, T;
	cin >> N >> T;
	for(int i = 1; i <= N; i++){
		cin >> w[i] >> v[i];
		avg[i] = v[i] / (1. * w[i]);
		indexs[i] = i;
	}
	// 不包括最后一个
	sort(indexs + 1, indexs + N + 1, cmp);
	double ans = 0.;
	for(int i = 1; i <= N; i++){
		if(T >= w[indexs[i]]){
			ans += v[indexs[i]];
			T -= w[indexs[i]];
		}else{
			ans += avg[indexs[i]] * T;
			break;
		}
	}
	printf("%.2lf", ans);
	return 0;
}