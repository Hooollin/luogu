#include <iostream>
#include <string> 
#include <cstring>
using namespace std;

int maxn = 1e4 + 5;

int main(){
	int n;
	cin >> n;
	int _ans[maxn];
	int _len = 1;
	memset(_ans, 0, maxn);
	_ans[0] = 1;
	for(int x = 2; x <= n; x++){
		int ans[maxn];
		memset(ans, 0, maxn);
		ans[0] = 1;
		int len = 1;
		for(int i = 2; i <= x; i++){
			int k = 0;
			for(int j = 0; j < len; j++){
				ans[j] = k + ans[j] * i;
				k = ans[j] / 10;
				ans[j] %= 10;
			}
			while(k > 0){
				ans[len++] = k % 10;
				k /= 10;
			}
		}
		int carry = 0;
		for(int i = 0; i < max(len, _len); i++){
			_ans[i] = _ans[i] + ans[i] + carry;
			carry = _ans[i] / 10;
			_ans[i] %= 10;
		}
		_len = max(len, _len);
		while(carry > 0){
			_ans[len++] = carry % 10;
			carry /= 10;
		}
	}
	for(int i = _len - 1; i >= 0; i--){
		cout << _ans[i];
	}
	return 0;
}
