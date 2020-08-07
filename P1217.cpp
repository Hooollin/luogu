#include <bits/stdc++.h>
using namespace std;

bool is(int i){
	string s = to_string(i);
	for(int k = 0; k < s.size() / 2; k++){
		if(s[k] != s[s.size() - k - 1]){
			return false;
		}
	}
	return true;
}


bool isP(int i){
	if(i == 1 || i == 2){
		return true;
	}
	for(int k = 2; k * k <= i; k++){
		if(i % k == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int a, b;
	cin >> a >> b;
	for(int i = a & 1 ? a : a + 1; i <= b; i += 2){
		if(is(i) && isP(i)){
			cout << i << endl;
		}
	}
	return 0;
}