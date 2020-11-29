#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/daily-temperatures/ (MEDIUM level)

vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> s;
    int n = T.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
       while (!s.empty() && T[i] > T[s.top()]) {
           ans[s.top()] = i - s.top();
           s.pop();
       }
        s.push(i);
    }

    while (!s.empty()) {
        ans[s.top()] = 0;
        s.pop();
    }

    return ans;
}

int main() {
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(temp);
    for (int daysToWait: ans) {
        cout << daysToWait << ", ";
    }
    cout << endl;
    return 0;
}
