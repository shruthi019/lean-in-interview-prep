#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/next-greater-element-ii/ (MEDIUM level)

vector<int> next_greater_element(vector<int> v) {
    int n = v.size();
    vector<int> ans(n);
    stack<int> s;

    for (int i = 0; i < 2 * n; i++) {
        while (!s.empty() && v[i % n] > v[s.top()]) {
            ans[s.top()] = v[i % n];
            s.pop();
        }
        if (i < n) {
            s.push(i);
        }
    }

    while (!s.empty()) {
        ans[s.top()] = -1;
        s.pop();
    }

    return ans;
}

int main() {
    vector<int> v = {1, 2, 1};
    vector<int> ans = next_greater_element(v);

    for (int x: ans) {
        cout << x << " ";
    }

    return 0;
}