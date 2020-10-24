#include <iostream>
using namespace std;

// Problem: https://www.geeksforgeeks.org/selection-sort/

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;

    return;
}

void selection_sort(int *arr, int n) {
    // Time Complexity: O(n^2)

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        swap(&arr[min_idx], &arr[i]);
    }

    return;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
