//
// _vector.cpp 
// Created by Hollin on 7/26/2020
//

#include <vector>
#include <iostream>

using namespace std;

int main(){
    // create an empty vector v1
    vector<int> v1;
    // create an vector v2 from array arr
    int arr[] = {1, 2, 3, 4};
    vector<int> v2(arr, arr + 4);
    // resize v2 to the size of 10, fill value of 5
    v2.resize(10, 2);
    // remove trailing elements from index 4 in v2
    v2.erase(v2.begin() + 4, v2.begin() + v2.size());
    // get the front elem and the back elem in vector then add.
    cout << v2.front() + v2.back() << endl;
    // reverse vector by swap
    for(int i = 0; i < v2.size() / 2; i++){
        swap(v2[i], v2[v2.size() - i - 1]);
    }
    // fill empty vector v1 to the size of ten with value 5
    v1.assign(10, 5);
    // push 6 to the end of v1, then pop all the elems out
    v1.push_back(6);
    // or you can just clear v1
    v1.clear();
    cout << v1.size() << endl;
    return 0;
}
