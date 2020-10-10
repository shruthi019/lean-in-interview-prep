#include <iostream>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/sort-array-by-parity/ (EASY level)

vector<int> sort_parity(vector<int> v) {
    int i = 0;
    int j = v.size() - 1;
    while (i < j) {
        if (v[i] % 2 > v[j] % 2) {
            swap(v[i], v[j]);
        } 

        if (v[i] % 2 == 0) {
            i++;
        }

        if (v[j] % 2 == 1) {
            j--;
        }
    }

    return v;
}


int main() {
    vector<int> v = {3, 1, 2, 4};
    vector<int> sorted_by_parity = sort_parity(v);

    for (int x: sorted_by_parity) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}