#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> maxis(n);
    for(int i = 0; i < n; i++){
        cin >> maxis[i];
    }
    sort(maxis.begin(), maxis.end());
    long long ans = maxis[0];
    for(int i = 1; i < n; i++){
        ans *= (maxis[i] - i);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}