#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem: https://leetcode.com/problems/subarray-sum-equals-k/ (MEDIUM level)

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int cum_sum = 0;
    m[0] = 1;
    int count = 0;
    
    // [1,2,3,-3,3]
    // 1 3 6 3 6
    for (int x: nums) {
        cum_sum += x;
        if (m.find(cum_sum - k) != m.end()) {
            count += m[cum_sum - k];
        }
        m[cum_sum]++;
    }
  
    return count;
}

int main() {
	vector<int> v = {1, 2, 3, -3, 3};
	int k = 3;

	cout << subarraySum(v, k) << endl;

	return 0;
}