#include <iostream>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/global-and-local-inversions/ (MEDIUM level)

bool isIdealPermutation(vector<int> v) {
    int max_val = -1;
    for (int i = 0; i < v.size() - 2; i++) {
        max_val = max(max_val, v[i]);
        if (max_val > v[i + 2]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> v = {1, 0, 2};
    cout << isIdealPermutation(v) << endl;
    return 0;
}