#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct{
	string name;
	int origin;
	int contri;
	int level;
}man;

bool cmp(man &a, man &b){
	if(a.contri != b.contri){
		return a.contri > b.contri;
	}
	if(a.level != b.level){
		return a.level > b.level;
	}
	return a.origin > b.origin;
}

bool cmp2(man &a, man &b){
	if(a.origin != b.origin){
		return a.origin > b.origin;
	}
	if(a.level != b.level){
		return a.level > b.level;
	}
}

int to_origin(string s){
	if(s == "BangZhu"){
		return 5;
	}
	if(s == "FuBangZhu"){
		return 4;
	}
	if(s == "HuFa"){
		return 3;
	}
	if(s == "ZhangLao"){
		return 2;
	}
	if(s == "TangZhu"){
		return 1;
	}
	if(s == "JingYing"){
		return 0;
	}
	if(s == "BangZhong"){
		return -1;
	}
}

string occupation(int i){
	if(i <= 1){
		return "HuFa";
	}else if(i <= 5){
		return "ZhangLao";
	}else if(i <= 12){
		return "TangZhu";
	}else if(i <= 27){
		return "JingYing";
	}else{
		return "BangZhu";
	}
}

int main(){
	int n;
	cin >> n;
	man mans[n];
	vector<man> tosort;
	vector<man> heads;
	for(int i = 0; i < n; i++){
		string origin;
		cin >> mans[i].name >> origin >> mans[i].contri >> mans[i].level;
		mans[i].origin = to_origin(origin);
		if(origin == "BangZhu" || origin == "FuBangZhu"){
			heads.push_back(mans[i]);
		}else{
			tosort.push_back(mans[i]);
		}
	}

	sort(tosort.begin(), tosort.end(), cmp);
	for(int i = 0; i < heads.size(); i++){
		if(heads[i].origin == 5){
			cout << heads[i].name << " " << "Bangzhu" << " " << heads[i].level << endl;
		}
	}
	for(int i = 0; i < heads.size(); i++){
		if(heads[i].origin == 4){
			cout << heads[i].name << " " << "FuBangZhu" << " " << heads[i].level << endl;
		}
	}

	for(int i = 0; i < tosort.size(); i++){
		tosort[i].origin = to_origin(occupation(i));
		//cout << tosort[i].name << " " << occupation(i) << " " << tosort[i].level << endl;
	}

	sort(tosort.begin(), tosort.end(), cmp2);

	for(int i = 0; i < tosort.size(); i++){
		cout << tosort[i].name << " " << occupation(i) << " " << tosort[i].level << endl;
	}
	return 0;
}