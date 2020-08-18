//
// P1030.cpp 
// Created by Hollin on 8/11/2020
//
#include <bits/stdc++.h>
using namespace std;

void getPre(string in, string post, int istart, int iend, int root){
    if(istart > iend || root < 0){
        return;
    }
    //cout << root << endl;
    //cout << root << endl;
    //cout << post[root] << endl;
    int idx = istart;
    while(idx < iend){
        if(in[idx] == root){
            break;
        }
        idx += 1;
    }
    cout << idx << endl;
    getPre(in, post, istart, idx - 1, idx - 1);
    getPre(in, post, istart, idx + 1, root - 1);
}

int main(){
    string in, post;
    cin >> in >> post;
    getPre(in, post, 0, in.size() - 1, post.size() - 1);
    return 0;
}