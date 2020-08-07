#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 2;
int arr[maxn];
bool valid(int len, int N, int M){
	int i = 0, j = 1;
	while(j < N){
		if(arr[i] + len > arr[j]){
			j += 1;
			M -= 1;
		}else{
			i = j;
			j += 1;
		}
		if(M < 0){
			return false;
		}
	}
	return true;
}

int main(){
	int L, N, M;
	cin >> L >> N >> M;
	arr[0] = 0;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	arr[N + 1] = L;
	int s = 0, e = L;
	int ans = L;
	while(s <= e){
		int mid = s + (e - s) / 2;
		if(valid(mid, N + 2, M)){
			ans = mid;
			s = mid + 1;
		}else{
			e = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}