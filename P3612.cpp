#include <bits/stdc++.h>

using namespace std;

int main(){
	string word;
	long long n;
	cin >> word >> n;
	if(n < word.size()){
		cout << word[n - 1] << endl;
		return 0;
	}
	long long len = word.size();
	while(len <= n){
		len *= 2;
	}
	while(n > word.size()){
		if(n == len / 2 + 1){
			n = len / 2;
		}else if(n > len / 2 + 1){
			n = n - len / 2 - 1;
		}
		len /= 2;
	}
	cout << word[n - 1] << endl;
	return 0;
}