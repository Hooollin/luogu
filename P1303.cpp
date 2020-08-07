#include <iostream>

using namespace std;
const int maxn = 2e6 + 5;
int main(){
	int a[maxn], b[maxn], ans[maxn];
	string number;
	cin >> number;
	int m = number.size();
	for(int i = 0; i < number.size(); i++){
		a[i] = number[m - i - 1] - '0';
	}
	cin >> number;
	int n = number.size();
	for(int i = 0; i < number.size(); i++){
		b[i] = number[n - i - 1] - '0';
	}
	int carry = 0;
	int base = 1;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			ans[i + j] += a[i] * b[j];
			ans[i + j + 1] += ans[i + j] / 10;
			ans[i + j] %= 10;
		}
	}
	int len = m + n;
	while(len >= 1 && ans[len] == 0){
		len--;
	}
	for(int i = len; i >= 0; i--){
		cout << ans[i];
	}
	return 0;
}