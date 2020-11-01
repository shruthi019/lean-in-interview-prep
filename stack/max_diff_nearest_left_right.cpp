#include <iostream>
#include <stack>
using namespace std;

// Problem: https://www.geeksforgeeks.org/find-maximum-difference-between-nearest-left-and-right-smaller-elements/

int* nearest_right_smaller(int* arr, int n) {
    stack<int> s;
    int* ans = new int[n];

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] < arr[s.top()]) {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {
        ans[s.top()] = 0;
        s.pop();
    }

    return ans;
}

int* nearest_left_smaller(int* arr, int n) {
    stack<int> s;
    int* ans = new int[n];

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] < arr[s.top()]) {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {
        ans[s.top()] = 0;
        s.pop();
    }

    return ans;
}

// Naive solution - first compute nearest left smaller for all elements, and nearest right smaller for all elements
// Then calculate abs diff and return max diff
int max_diff(int* arr, int n) {
    int* nls = nearest_left_smaller(arr, n);
    int* nrs = nearest_right_smaller(arr, n);

    int max_abs_diff = -1;

    for (int i = 0; i < n; i++) {
        max_abs_diff = max(max_abs_diff, abs(nrs[i] - nls[i]));
    }

    return max_abs_diff; 
}

// Efficient solution in one traversal of array
// we use the fact that while calculating nearest right smaller, we also get the nearest left smaller as the element in stack just before the current element
// if no such element exists, then there is no nearest left smaller for the element and we take it to be 0 as given in the question
int max_diff_eff(int* arr, int n) {
    stack<int> s;
    int max_abs_diff = -1;
    int nsr, nsl;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] < arr[s.top()]) {
            nsr = arr[i];
            s.pop();
            nsl = (s.empty() ? 0: arr[s.top()]);
            max_abs_diff = max(max_abs_diff, abs(nsr - nsl));
        }
        s.push(i);
    }

    while (!s.empty()) {
        nsr = 0;
        s.pop();
        nsl = (s.empty() ? 0: arr[s.top()]);
        max_abs_diff = max(max_abs_diff, abs(nsr - nsl));
    }

    return max_abs_diff;
}

int main() {
    int arr[] = {2, 4, 8, 7, 7, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << max_diff(arr, n) << endl;
    cout << max_diff_eff(arr, n) << endl;
    return 0;
}