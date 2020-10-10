#include <iostream>
using namespace std;

// Problem: https://leetcode.com/problems/first-missing-positive/ (HARD level)

int first_missing_positive(int* arr, int n) {
    int i = 0;

    while (i < n) {
        if (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
            swap(arr[i], arr[arr[i] - 1]);
        } else {
            i++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {
    int arr[] = {3, 4, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << first_missing_positive(arr, n) << endl;

    return 0;
}