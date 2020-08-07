#include <bits/stdc++.h>

using namespace std;
int idx = 0;
string parse(string str){
	string ans = "";
	while(idx < str.size()){
		if(str[idx] == '['){
			idx += 1;
			int t = 0;
			while(isdigit(str[idx])){
				t = t * 10 + str[idx] - '0';
				idx += 1;
			}
			string rev = parse(str);
			for(int i = 0; i < t; i++){
				ans += rev;
			}
		}else if(str[idx] == ']'){
			idx += 1;
			return ans;
		}else if(isalpha(str[idx])){
			ans += str[idx];
			idx += 1;
		}
	}
	return ans;
}

int main(){
	string str;
	cin >> str;
	cout << parse(str);
	return 0;
}