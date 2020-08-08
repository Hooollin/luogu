//
// P1827.cpp 
// Created by Hollin on 8/8/2020
//
#include <bits/stdc++.h>
using namespace std;

int get(int start, int end, string inorder, string tar){
    while(start <= end){
        if(inorder.substr(start, 1) == tar){
            return start;
        }
        start += 1;
    }
    return -1;
}

string postorder(string inorder, string preorder, int pstart, int pend, int istart, int iend){
    //cout << start << " " << end << endl;
    if(istart > iend || pstart > pend){
        return "";
    }
    if(istart == iend){
        return inorder.substr(istart, 1);
    }
    string root = preorder.substr(pstart, 1);
    int iidx = get(istart, iend, inorder, root);
    return postorder(inorder, preorder, pstart + 1, pend, istart, iidx - 1)
    + postorder(inorder, preorder, pstart + iidx - istart + 1, pend, iidx + 1, iend) + root;

}

int main(){
    string inorder, preorder;
    cin >> inorder >> preorder;
    cout << postorder(inorder, preorder, 0, inorder.size() - 1, 0, inorder.size() - 1) << endl;
    return 0;
}