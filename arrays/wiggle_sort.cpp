#include <iostream>
#include <vector>
using namespace std;

// Problem: https://www.lintcode.com/problem/wiggle-sort/description (MEDIUM level)

void wiggleSort(vector<int>& nums) {
    int size = nums.size();

    for (int i = 0; i < size; i += 2) {
        if (i > 0 && nums[i] > nums[i - 1]) {
            swap(nums[i], nums[i - 1]);
        }
        if (i < size - 1 && nums[i] > nums[i + 1]) {
            swap(nums[i], nums[i + 1]);
        }
    }
    
    return;
}

int main() {
    vector<int> v = {3, 5, 2, 1, 6, 4};

    wiggleSort(v);

    for (int x: v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}