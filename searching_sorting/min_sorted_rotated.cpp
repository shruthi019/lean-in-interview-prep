#include <iostream>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ (MEDIUM level)

int find_pivot(vector<int>& nums, int lo, int hi) {
    if (hi < lo) {
        return -1;
    }
    
    int mid = lo + (hi - lo) / 2;
    
    if (mid > lo && nums[mid] < nums[mid - 1]) {
        return mid - 1;
    } 
    
    if (mid < hi && nums[mid] > nums[mid + 1]) {
        return mid;
    }
    
    if (nums[lo] <= nums[mid]) {
        return find_pivot(nums, mid + 1, hi);
    }
    
    return find_pivot(nums, lo, mid - 1);
}

int findMin(vector<int>& nums) {
    // TC: O(logn)
    return nums[find_pivot(nums, 0, nums.size() - 1) + 1];   
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << findMin(nums) << endl;
    return 0;
}