#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Problem: https://leetcode.com/problems/maximal-rectangle/ (HARD level)

int maxArea(vector<int> heights) {
    int nsr, nsl, height;
    stack<int> s;
    int n = heights.size();
    int max_area = 0;
    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] > heights[i]) {
            nsr = i;
            height = heights[s.top()];
            s.pop();
            nsl = s.empty() ? -1: s.top();
            max_area = max(max_area, height * (nsr - nsl - 1));
        }    
        s.push(i);
    }
    
    while (!s.empty()) {
        nsr = n;
        height = heights[s.top()];
        s.pop();
        nsl = s.empty() ? -1: s.top();
        max_area = max(max_area, height * (nsr - nsl - 1));
    }
    
    return max_area;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    if (n == 0) {
        return 0;
    }
    int cols = matrix[0].size();
    
    vector<int> height(cols);
    int max_area = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '0') {
                height[j] = 0;
            } else {
                height[j]++;
            }
        }
        max_area = max(max_area, maxArea(height));
    }
    
    return max_area;
}

int main() {
    vector<vector<char> > matrix { {'1','0','1','0','0'},
                                     {'1','0','1','1','1'},
                                     {'1','1','1','1','1'},
                                     {'1','0','0','1','0'} };
    cout << maximalRectangle(matrix) << endl;
    return 0;
}
