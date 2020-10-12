#include <iostream>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/optimal-division/ (MEDIUM level)

string optimal_div(vector<int> nums) {
    if (nums.size() == 1) {
        return to_string(nums[0]);
    }

    if (nums.size() == 2) {
        return to_string(nums[0]) + "/" + to_string(nums[1]);
    }

    string ans = to_string(nums[0]) + "/(" + to_string(nums[1]);
    for (int i = 2; i < nums.size(); i++) {
        ans += "/";
        ans += to_string(nums[i]);
    }
    ans += ")";
    
    return ans;
}

int main() {
    vector<int> nums = {1000,100,10,2};
    cout << optimal_div(nums) << endl;
    return 0;
}