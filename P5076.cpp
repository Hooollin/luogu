//
// P5076.cpp 
// Created by Hollin on 8/10/2020
//

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
typedef struct node{
    node *left;
    node *right;
    int val;
    int cnt;
}BSTNode, *BST;

void insert(BST root, int val){
    if(root == nullptr){

    }
    if(root->val == val){
        root->cnt += 1;
    }else if(root->val > val){
        if(root->left != nullptr) insert(root->left, val);
        else{
            BSTNode* now = new BSTNode();
            now->val = val;
            now->left = nullptr;
            now->right = nullptr;
            now->cnt = 1;
            root->left = now;
        }
    }else if(root->val < val){
        if(root->right != nullptr) insert(root->right, val);
        else{
            BSTNode *now = new BSTNode();
            now->val = val;
            now->left = nullptr;
            now->right = nullptr;
            now->cnt = 1;
            root->right = now;
        }
    }
}

int count(BST root){
    if(root == nullptr){
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}

int _rank(BST root, int val){
    if(root == nullptr){
        return 0;
    }
    if(root->val == val){
        return count(root->left) + 1;
    }
    if(root->val > val){
        return _rank(root->left, val);
    }
    return count(root->left) + _rank(root->right, val) + 1;
}

BSTNode* pre(BST root, BSTNode* prev, int val){
    if(root == nullptr){
        return nullptr;
    }
    BSTNode *left = pre(root->left, prev, val);
    if(left != nullptr){
        return left;
    }
    if(val == root->val){
        return prev;
    }
    BSTNode *right = pre(root->right, root, val);
    return right;
}

BSTNode* behind(BST root, BSTNode *prev, int val){
    if(root == nullptr){
        return nullptr;
    }
    if(prev != nullptr){
        return root;
    }
    BSTNode *left = behind(root->left, prev, val);
    if(left != nullptr){
        return left;
    }
    if(root->val == val){
        prev = root;
    }
    return behind(root->right, prev, val);
}

BSTNode* getval(BST root, int rank, int &now){
    if(root == nullptr){
        return nullptr;
    }
    //cout << "root->val:" << root->val << " now:" << now << endl;
    BSTNode* left = getval(root->left, rank, now);
    if(left != nullptr){
        return left;
    }
    now += root->cnt;
    if(now >= rank){
        return root;
    }
    return getval(root->right, rank, now);
}

int main(){
    BST root = nullptr;
    int n;
    cin >> n;
    while(n-- > 0){
        int k, val;
        cin >> k >> val;
        if(k == 1){
            cout << _rank(root, val) << endl;
        }else if(k == 2){
            int now = 0;
            cout << getval(root, val, now)->val << endl;
        }else if(k == 3){
            BSTNode *last = pre(root, nullptr, val);
            if(last == nullptr){
                cout << 2147483647 << endl;
            }else cout << last->val << endl;
        }else if(k == 4){
            BSTNode *next = behind(root, nullptr, val);
            if(next == nullptr){
                cout << -2147483647 << endl;
            }else cout << next->val << endl;
        }else if(k == 5){
            if(root == nullptr){
                root = new BSTNode();
                root->val = val;
                root->cnt = 1;
                root->left = nullptr;
                root->right = nullptr;
            }else{
                insert(root, val);
            }
        }
    }
    return 0;
}
