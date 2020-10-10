#include <iostream>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/product-of-array-except-self/ (MEDIUM level)

vector<int> product_except_self(vector<int> v) {
    int n = v.size();
    vector<int> ans(n);

    ans[0] = 1;

    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] * v[i - 1];
    }

    int right = 1;

    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= right;
        right *= v[i];
    }

    return ans;
}

int main() {
    vector<int> v = {1, 2, 3, 4};
    vector<int> product = product_except_self(v);

    for (int x: product) {
        cout << x << " ";
    }

    cout << endl;
    
    return 0;
}