#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 1;
int a[N], b[N], c[N];
int lena = 0, lenb = 0, lenc = 0;

void cover(){
	for(int j = 0; j < lenb; j++){
		a[j] = b[j];
	}
	lena = lenb;
	for(int j = 0; j < lenc; j++){
		b[j] = c[j];
	}
	lenb = lenc;
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
 		c[k] = carry + a[i++];
 		carry = c[k] / 10;
 		c[k++] %= 10;
 	}
 	while(j < lenb){
 		c[k] = carry + b[j++];
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
	int n;
	cin >> n;
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	memset(c, 0, sizeof c);
	if(n == 0){
		cout << 0 << endl;
		return 0;
	}
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	a[0] = 1;
	b[0] = 1;
	lena = 1, lenb = 1;
	for(int i = 2; i <= n; i++){
		add();
	}
	for(int i = lenc - 1; i >= 0; i--){
		cout << c[i];
	}
	return 0;
}