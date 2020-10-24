#include <iostream>
using namespace std;

// Problem: https://www.geeksforgeeks.org/bubble-sort/

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;

    return;
}

void bubble_sort(int *arr, int n) {
    // Time Complexity: O(n^2)

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                swap(&arr[j], &arr[i]);
            }
        }
    }

    return;
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bubble_sort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
