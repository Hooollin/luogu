//
// P1305.cpp 
// Created by Hollin on 8/10/2020
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 26;
int tree[maxn][2];

void preorder(int root){
    if(root == -1){
        return;
    }
    cout << (char)(root + 'a');
    preorder(tree[root][0]);
    preorder(tree[root][1]);
}

int main(){
    memset(tree, -1, sizeof tree);
    int n;
    cin >> n;
    bool first = true;
    int root;
    while(n-- > 0){
        char a, b, c;
        cin >> a >> b >> c;
        //cout << a << " " << b << " " << c << endl;
        if(b == '*'){
            b = 'a' - 1;
        }
        if(c == '*'){
            c = 'a' - 1;
        }
        a -= 'a', b -= 'a', c -= 'a';
        if(first){
            root = a;
            first = !first;
        }
        //cout << (int)a << " " << (int)b << " " << (int)c << endl;
        tree[a][0] = b;
        tree[a][1] = c;
    }
    preorder(root);
    return 0;
}