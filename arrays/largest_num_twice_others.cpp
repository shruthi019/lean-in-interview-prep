#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Problem: https://leetcode.com/problems/largest-number-at-least-twice-of-others/ (EASY level)

int dominantIndex(vector<int>& nums) {
    int size = nums.size();
    int max1 = INT_MIN;
    int max_idx = -1;
    
    for (int i = 0; i < size; i++) {
        if (nums[i] > max1) {
            max1 = nums[i];
            max_idx = i;
        }
    }
    
    for (int i = 0; i < size; i++) {
        if (i != max_idx) {
            if (nums[i] * 2 > max1) {
                return -1;
            }
        }
    }
    
    return max_idx;
}

int main() {
    vector<int> v = {1, 2, 3, 4};
    // vector<int> v = {1, 2, 4};
    cout << dominantIndex(v) << endl;
    return 0;
}