#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 * 5;
const int mod = 1e9 + 7;

long long C(long long x, long long k) { 
  return (k == 1ll ? x : x * (x - 1ll) / 2ll) % mod;
}

int buckets[N];
int main(){
	int n;
	cin >> n;
	int maxl = 0;
	for(int i = 0; i <= maxl; i++){
		buckets[i] = 0;
	}
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		buckets[t] += 1;
		maxl = max(maxl, t);
	}
	long long ans = 0;
	for(int i = 1; i <= maxl; i++){
		long long possi = C(buckets[i], 2);
		if(buckets[i] >= 2){
			for(int j = 1; j <= i / 2; j++){
				if(j != i - j && buckets[j] >= 1 && buckets[i - j] >= 1){
					ans += (((possi * buckets[j]) % mod) * buckets[i - j]) % mod;
					ans %= mod;
				}
				if(j = i - j && buckets[j] >= 2){
					ans += possi * C(buckets[j], 2) % mod;
					ans %= mod;
				}
			}
		}	
	}
	cout << ans << endl;
}