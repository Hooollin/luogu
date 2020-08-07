#include <iostream>
#include <string>
using namespace std;

void solve(int d, int *arr, int n){
	if(d == n - 1){
		if(arr[d] == 0){
			return;
		}
		string out = "";
		if(arr[d] > 0){
			if(arr[d] != 1){
				out += to_string(arr[d]);
			}
		}else{
			if(arr[d] != -1){
				out += to_string(arr[d]);
			}else{
				out += "-";
			}
		}
		if(d > 1) cout << out << "x^" << d;
		else cout << out << "x";
		return;
	}
	solve(d + 1, arr, n);
	if(arr[d] == 0){
		return;
	}
	string out = "";
	if(arr[d] > 0){
		out += "+";
		if(arr[d] != 1){
			out += to_string(arr[d]);
		}
	}else{
		if(arr[d] == -1){
			out += "-";
		}else{
			out += to_string(arr[d]);
		}
	}
	if(d > 1) cout << out << "x^" << d;
	else cout << out << "x";
}

int main(){
	int n;
	cin >> n;
	n += 1;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[n - i - 1];
	}
	solve(1, arr, n);
	if(arr[0] != 0){
		if(arr[0] > 0){
			cout << "+" << arr[0];
		}else{
			cout << arr[0];
		}
	}
	return 0;
}
