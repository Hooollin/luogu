#include <iostream>
#include <string>

using namespace std;

int main(){
	string a, b;
	cin >> a >> b;
	int carry = 0;
	int i = a.size() - 1, j = b.size() - 1;
	string t;
	if(a.size() > b.size()){
		t = a;
	}else{
		t = b;
	}

	int idx = max(a.size(), b.size()) - 1;

	while(i >= 0 && j >= 0){
		int sum = a[i] + b[j] - 2 * '0' + carry;
		carry = sum / 10;
		t[idx--] = '0' + sum % 10; 
		i--;j--;
	}

	while(i >= 0){
		int sum = a[i] + carry - '0';
		carry = sum / 10;
		t[idx--] = '0' + sum % 10;
		i--;
	}
	while(j >= 0){
		int sum = b[j] + carry - '0';
		carry = sum / 10;
		t[idx--] = '0' + sum % 10;
		j--;
	}
	if(carry > 0){
		cout << carry;
	}
	cout << t;
	return 0;
}
