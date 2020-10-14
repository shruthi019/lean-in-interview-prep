#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Problem: https://leetcode.com/problems/maximum-product-of-three-numbers/ (EASY level)

int max_product(vector<int> v) {
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] < min1) {
            min2 = min1;
            min1 = v[i];
        } else if (v[i] < min2) {
            min2 = v[i];
        }

        if (v[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = v[i];
        } else if (v[i] > max2) {
            max3 = max2;
            max2 = v[i];
        } else if (v[i] > max3) {
            max3 = v[i];
        }
    }

    return max(max1 * max2 * max3, max1 * min1 * min2);
}

int main() {
    vector<int> v = {-4, -3, -2, 1, 10};
    // vector<int> v = {-4, -3, -2, 1, 10, 400};
    cout << max_product(v) << endl;
    return 0;
}