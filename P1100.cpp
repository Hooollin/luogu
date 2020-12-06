#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int h_mask = 0xffff0000;
    int l_mask = 0x0000ffff;
    unsigned int ans = ((n & l_mask) << 16) | ((unsigned)(n & h_mask) >> 16);
    cout << ans << endl;
    return 0;
}