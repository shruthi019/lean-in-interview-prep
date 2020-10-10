#include <iostream>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/container-with-most-water/ (MEDIUM levels)

int max_water(vector<int> &heights) {
    int n = heights.size();

    int i = 0, j = n - 1;
    int max_area = -1;

    while (i < j) {
        max_area = max(max_area, min(heights[i], heights[j]) * (j - i));
        if (heights[i] < heights[j]) {
            i++;
        } else {
            j--;
        }
    }

    return max_area;
}

int main() {
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    cout << max_water(heights) << endl;
    return 0;
}