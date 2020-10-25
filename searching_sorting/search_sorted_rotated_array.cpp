#include <iostream>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/

int binary_search(vector<int>& nums, int lo, int hi, int key) {
    if (hi < lo) {
        return -1;
    }
    
    int mid = (lo + hi) / 2;
    
    if (key == nums[mid]) {
        return mid;
    }
    
    if (key > nums[mid]) {
        return binary_search(nums, mid + 1, hi, key);
    }
    
    return binary_search(nums, lo, mid - 1, key);
}

int find_pivot(vector<int>& nums, int lo, int hi) {
    if (hi < lo) {
        return -1;
    }
    
    if (hi == lo) {
        return hi;
    }
    
    int mid = (hi + lo) / 2;
    
    if (mid < hi && nums[mid] > nums[mid + 1]) {
        return mid;
    } 
    
    if (mid > lo && nums[mid] < nums[mid - 1]) {
        return mid - 1;
    }
    
    if (nums[lo] > nums[mid]) {
        return find_pivot(nums, lo, mid - 1);
    }
    
    return find_pivot(nums, mid + 1, hi);
}

int search(vector<int>& nums, int target) {
    int pivot = find_pivot(nums, 0, nums.size() - 1);
    
    if (pivot == -1) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }
    
    if (nums[pivot] == target) {
        return pivot;
    }
    
    if (nums[0] <= target) {
        return binary_search(nums, 0, pivot - 1, target);
    }
    
    return binary_search(nums, pivot + 1, nums.size() - 1, target);
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    cout << search(nums, target) << endl;
    return 0;
}