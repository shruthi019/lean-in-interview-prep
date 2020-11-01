#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Problem: https://www.geeksforgeeks.org/next-greater-element/

vector<int> next_greater_element(vector<int> v) {
    int n = v.size();
    vector<int> ans(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && v[i] > v[s.top()]) {
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {
        ans[s.top()] = -1;
        s.pop();
    }

    return ans;
}

int main() {
    vector<int> v = {13, 7, 6, 12};
    vector<int> ans = next_greater_element(v);

    for (int x: ans) {
        cout << x << " ";
    }

    return 0;
}