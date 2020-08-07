#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while(T-- > 0){
		int k;
		scanf("%d", &k);
		vector<double> v(k);
		for(int i = 0; i < k; i++){
			scanf("%lf", &v[i]);
		}
		sort(v.begin(), v.end());
		long long ans = 0;
		vector<long long> dsum(v.size());
		dsum[0] = 0;
		for(int i = 1; i < v.size(); i++){
			dsum[i] = i * (v[i] - v[i - 1]) + dsum[i - 1];
			ans += dsum[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}