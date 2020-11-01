#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/ (HARD level)

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int n = heights.size();
    int nsr, nsl, height;
    int max_area = 0;
    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            nsr = i;
            height = heights[s.top()];
            s.pop();
            nsl = (s.empty() ? -1: s.top());
            max_area = max(max_area, height * (nsr - nsl - 1));
        }
        s.push(i);
    }
    
    while (!s.empty()) {
        nsr = n;
        height = heights[s.top()];
        s.pop();
        nsl = (s.empty() ? -1: s.top());
        max_area = max(max_area, height * (nsr - nsl - 1));
    }
    
    return max_area;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}