#include <bits/stdc++.h>

using namespace std;

struct Stu{
	string name;
	int i;
	int year;
	int month;
	int day;
};
bool cmp(Stu &a, Stu &b){
	if(a.year != b.year){
		return a.year < b.year;
	}
	if(a.month != b.month){
		return a.month < b.month;
	}
	if(a.day != b.day){
		return a.day < b.day;
	}
	return a.i > b.i;
}


void print(Stu s){
	cout << s.name << endl;
}

int main(){
	int n;
	vector<Stu> ss;
	cin >> n;
	for(int i = 0; i < n; i++){
		Stu t;
		cin >> t.name >> t.year >> t.month >> t.day;
		t.i = i;
		ss.push_back(t);
	}
	sort(ss.begin(), ss.end(), cmp);
	for(int i = 0; i < ss.size(); i++){
		print(ss[i]);
	}
	return 0;
}