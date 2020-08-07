#include <iostream>
#include <string>
using namespace std;

int main(){
	string info;
	string line;
	while(cin >> line){
		info += line;
	}
	int ws = 0, ls = 0;
	for(int i = 0; i < info.size(); i++){
		if(info[i] == 'E'){
			cout << ws << ":" << ls << endl;
			ws = 0;
			ls = 0;
			break;
		}
		if(info[i] == 'W'){
			ws += 1;
		}else{
			ls += 1;
		}
		if(ws >= 11 && ws >= ls + 2 || ls >= 11 && ws + 2 <= ls){
			cout << ws << ":" << ls << endl;
			ws = 0;
			ls = 0;
		}
	}

	cout << endl;

	for(int i = 0; i < info.size(); i++){
		if(info[i] == 'E'){
			cout << ws << ":" << ls;
			break;
		}
		if(info[i] == 'W'){
			ws += 1;
		}else{
			ls += 1;
		}
		if(ws >= 21 && ws >= ls + 2 || ls >= 21 && ws + 2 <= ls){
			cout << ws << ":" << ls << endl;
			ws = 0;
			ls = 0;
		}
	}
	return 0;
}