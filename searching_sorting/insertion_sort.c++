#include <iostream>
using namespace std;

// Problem: https://www.geeksforgeeks.org/insertion-sort/

void insertion_sort(int *arr, int n) {
    // Time Complexity: O(n^2)

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    return;
}

int main() {
    int arr[] = {37, 18, 3, 8, -8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    insertion_sort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
