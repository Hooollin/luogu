//
// P1241.cpp 
// Created by Hollin on 8/7/2020
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    string input;
    cin >> input;
    bool closed[input.size()];
    memset(closed, 0, sizeof(closed));
    stack<char> stk;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == '(' || input[i] == '[') {
            stk.push(i);
            continue;
        }
        if(!stk.empty()){
            if(input[i] == ')' && input[stk.top()] == '('){
                closed[i] = true;
                closed[stk.top()] = true;
                stk.pop();
            }else if(input[i] == ']' && input[stk.top()] == '['){
                closed[i] = true;
                closed[stk.top()] = true;
                stk.pop();
            }
        }
    }
    for(int i = 0; i < input.size(); i++){
        if(closed[i]){
            cout << input[i];
        }else{
            if(input[i] == '('){
                cout << "()";
            }
            if(input[i] == '['){
                cout << "[]";
            }
            if(input[i] == ')'){
                cout << "()";
            }
            if(input[i] == ']'){
                cout << "[]";
            }
        }
    }
    return 0;
}