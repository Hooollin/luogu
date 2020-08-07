#include <bits/stdc++.h>

using namespace std;
int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
bool vis[9];
int A, B, C;
int ans = 0;
void dfs(string a, string b, string c){
	if(a.size() == 3 && b.size() == 3 && c.size() == 3){
		int ai = stoi(a), bi = stoi(b), ci = stoi(c);
		if(ai % A == 0 && bi % B == 0 && ci % C == 0){
			if(ai / A == bi / B && bi / B == ci / C){
				cout << ai << " " << bi << " " << ci << endl;
				ans += 1;
			}
		}
		return;
	}else{
		for(int i = 0; i < 9; i++){
			if(vis[i]){
				continue;
			}
			vis[i] = true;
			if(a.size() < 3){
				dfs(a + to_string(arr[i]), b, c);
			}else if(b.size() < 3){
				dfs(a, b + to_string(arr[i]), c);
			}else{
				dfs(a, b, c + to_string(arr[i]));
			}
			vis[i] = false;
		}
	}

}

int main(){
	cin >> A >> B >> C;
	memset(vis, 0, sizeof vis);
	dfs("", "", "");
	if(ans == 0){
		cout << "No!!!" << endl;
	}
	return 0;
}