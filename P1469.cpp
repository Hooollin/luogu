#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n; 
    int ans = 0;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        ans ^= t;
    }
    cout << ans;
    return 0;
}