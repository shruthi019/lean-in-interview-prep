#include <iostream>
#include <algorithm>
using namespace std;

// Problem: Given an unsorted array and a number n, find if there exists a pair of elements in the array whose difference is n.
// https://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/

pair<int, int> two_difference(int* arr, int n, int target) {
    sort(arr, arr + n);
    int i = 0, j = 1;

    while (i < j) {
        if (arr[j] - arr[i] == target) {
            return make_pair(arr[j], arr[i]);
        } else if (arr[j] - arr[i] > target) {
            i++;
        } else {
            j++;
        }
    }

    cout << "No pair exists" << endl;
    exit(1);
}

int main() {
    int arr[] = {1, 8, 30, 40, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 610;

    pair<int, int> p = two_difference(arr, n, target);

    cout << "Pair: " << p.first << " " << p.second << endl;
    return 0;
}