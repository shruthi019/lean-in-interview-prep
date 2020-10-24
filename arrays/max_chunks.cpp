#include <iostream>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/max-chunks-to-make-sorted/

int maxChunksToSorted(vector<int>& arr) {
    // Time Complexity: O(n)

    int ans = 0, maxx = 0;

    for (int i = 0; i < arr.size(); i++) {
        maxx = max(maxx, arr[i]);
        if (maxx == i) {
            ans++;
        }
    }

    return ans;
}

int main() {
    vector<int> v = {4, 3, 2, 1, 0};
    cout << maxChunksToSorted(v) << endl;
    return 0;
}
