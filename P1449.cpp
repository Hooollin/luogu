//
// P1449.cpp 
// Created by Hollin on 7/28/2020
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    cin >> line;
    stack<int> s;
    int num = 0;
    for (int i = 0; i < line.size(); i++) {
        if (isdigit(line[i])) {
            num = num * 10 + (line[i] - '0');
            continue;
        } else if (line[i] == '.') {
            s.push(num);
            num = 0;
            continue;
        }else if(line[i] == '@'){
            break;
        }
        int n1 = s.top();
        s.pop();
        int n2 = s.top();
        s.pop();
        if(line[i] == '-'){
            s.push(n2 - n1);
        } else if (line[i] == '*') {
            s.push(n2 * n1);
        } else if (line[i] == '+'){
            s.push(n1 + n2);
        }else if(line[i] == '/'){
            s.push(n2 / n1);
        }
    }
    cout << s.top() << endl;
    return 0;
}