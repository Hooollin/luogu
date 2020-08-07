	#include <iostream>
	#include <string>
	#include <vector>
using namespace std;

int p1, p2, p3;
string str;
vector<char> ans;

void build(char start, char end){
	vector<char> t;
	while(++start < end){
		if(p1 == 1){
			for(int i = 0; i < p2; i++){
				if(isalpha(start))
					t.push_back(tolower(start));
				else t.push_back(start);
			}
		}else if(p1 == 2){
			for(int i = 0; i < p2; i++){
				if(isalpha(start)){
					t.push_back(toupper(start));
				}else{
					t.push_back(start);
				}
			}
		}else if(p1 == 3){
			for(int i = 0; i < p2; i++){
				t.push_back('*');
			}
		}
	}
	if(p3 == 2){
		for(int i = t.size() - 1; i >= 0; i--){
			ans.push_back(t[i]);
		}
	}else{
		for(int i = 0; i < t.size(); i++)
			ans.push_back(t[i]);
	}
}

void solve(){
	for(int i = 1; i < str.size(); i++){
		if(str[i] != '-'){
			ans.push_back(str[i - 1]);
		}else{
			char start = str[i - 1], end = str[i + 1];
			ans.push_back(start);
			if(start < end && ((isalpha(start) && isalpha(end)) || (isdigit(start) && isdigit(end)))){
				cout << start << ends << end << endl;
				build(start, end);
			} else ans.push_back('-');
			i += 1;
		}
	}
	ans.push_back(str[str.size() -1]);
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
	}
}

int main(){
	cin >> p1 >> p2 >> p3;
	cin >> str;
	solve();
	return 0;
}
