#include <bits/stdc++.h>
using namespace std;
typedef struct
{
	int num;
	int total;
	int yuwen;
	int shuxue;
	int yingyu;
}stu;

bool cmp(stu &a, stu &b){
	if(a.total != b.total){
		return a.total > b.total;
	}
	if(a.yuwen != b.yuwen){
		return a.yuwen > b.yuwen;
	}
	return a.num < b.num;
}

int main(){
	vector<stu> stus;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		stu t;
		t.num = i;
		cin >> t.yuwen >> t.shuxue >> t.yingyu;
		t.total = t.yuwen + t.shuxue + t.yingyu;
		stus.push_back(t);
	}
	sort(stus.begin(), stus.end(), cmp);
	for(int i = 0; i < 5; i++){
		cout << stus[i].num <<  " " << stus[i].total << endl;
	}
	return 0;
}