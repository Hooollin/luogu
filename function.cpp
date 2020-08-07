#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long f(long long i){
	long long ans = 0;
	for(long long j = 1; j <= i; j++){
		if(i % j == 0){
			if(__gcd(j, i / j) == 1){
				ans += j;
			}
		}
	}
	return ans;
}

int main(){
	int kases;
	scanf("%d", &kases);
	for(int _ = 0; _ < kases; _++){
		long long N;
		scanf("%ld", &N);
		long long ans = 0;
		for(int i = 1; i <= N; i++){
			ans += f(i);
			ans %= mod;
		}
		cout << ans << endl;
	}
	return 0;
}