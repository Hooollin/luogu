#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 1;

int a[N], b[N], c[N];
int lena, lenb, lenc;

void cover(){
	for(int i = 0; i < lena; i++){
		b[i] = a[i];
	}
	lenb = lena;
	for(int i = 0; i < lenc; i++){
		a[i] = c[i];
	}
	lena = lenc;
}

void add(){
	int i = 0, j = 0, k = 0;
	int carry = 0;
	while(i < lena && j < lenb){
		c[k] = a[i++] + b[j++] + carry;
		carry = c[k] / 10;
		c[k++] %= 10;
	}
	while(i < lena){
		c[k] = a[i++] + carry;
		carry = c[k] / 10;
		c[k++] %= 10;
	}
	while(j < lenb){
		c[k] = b[j++] + carry;
		carry = c[k] / 10;
		c[k++] %= 10;
	}
	if(carry > 0){
		c[k++] = carry;
	}
	lenc = k;
	cover();
}



int main(){
	int m, n;
	cin >> m >> n;
	if(m == n){
		cout << 1 << endl;
		return 0;
	}
	a[0] = 1;
	lena = 1;
	lenb = 0;
	for(int i = m + 1; i <= n; i++){
		add();
	}
	for(int i = lenc - 1; i >= 0; i--){
		cout << c[i];
	}
	return 0;
}