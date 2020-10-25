#include <iostream>
using namespace std;

// Problem: https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

pair<int, int> first_last_occ(int *arr, int n, int x) {
	// naive approach
	// loop through the array and update first and last indices as we find element
	// Time Complexity: O(n)

	int first = -1, last = -1;
	bool is_first = true;

	for (int i = 0; i < n; i++) {
		if (arr[i] == x && is_first) {
			first = i;
			last = i;
			is_first = !is_first;
		} else if (arr[i] == x) {
			last = i;
		}
	}

	return make_pair(first, last);
}

// Efficient approach using binary search
// TC: O(logn), SC: O(logn) - since recursive implementation

int first_occ(int* arr, int lo, int hi, int x) {
	if (hi < lo) {
		return -1;
	}

	int mid = (lo + hi) / 2;

	if (arr[mid] == x && (mid == 0 || arr[mid - 1] < arr[mid])) {
		return mid;
	}

	if (arr[mid] < x) {
		return first_occ(arr, mid + 1, hi, x);
	}

	return first_occ(arr, lo, mid - 1, x);

	// Note: The arr[mid] < x and fallback else condition cannot be switched.
	// edge case: {1, 3, 5, 5, 5, 5, 67, 123, 125} and target = 5
	// first occ of 5 will not be found if the 2 conditions are switched
}

int last_occ(int* arr, int lo, int hi, int x, int n) {
	if (hi < lo) {
		return -1;
	}

	int mid = (lo + hi) / 2;

	if (arr[mid] == x && (mid == n - 1 || arr[mid + 1] > arr[mid])) {
		return mid;
	}

	if (arr[mid] > x) {
		return last_occ(arr, lo, mid - 1, x, n);
	}

	return last_occ(arr, mid + 1, hi, x, n);

	// Note: The arr[mid] > x and fallback else condition cannot be switched.
	// edge case: {1, 3, 5, 5, 5, 5, 67, 123, 125} and target = 5
	// last occ of 5 will not be found if the 2 conditions are switched
}

pair<int, int> iterative_first_last(int* arr, int n, int x) {
	// TC: O(logn), SC: O(1)

	int lo = 0, hi = n - 1, first = -1, last = -1;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (arr[mid] < x) {
			lo = mid + 1;
		} else if (arr[mid] > x) {
			hi = mid - 1;
		} else {
			first = mid;
			hi = mid - 1;
		}
	}

	lo = 0, hi = n - 1;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (arr[mid] < x) {
			lo = mid + 1;
		} else if (arr[mid] > x) {
			hi = mid - 1;
		} else {
			last = mid;
			lo = mid + 1;
		}
	}

	return make_pair(first, last);
}

int main() {
	int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
	int x = 5;
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Using naive approach:" << endl;

	pair<int, int> p = first_last_occ(arr, n, x); 
	cout << p.first << ", " << p.second << endl;

	cout << "Using Efficient approach (recursive):" << endl;
	cout << first_occ(arr, 0, n - 1, x) << ", " << last_occ(arr, 0, n - 1, x, n) << endl;
	
	cout << "Using Efficient approach (iterative):" << endl;

	pair<int, int> fl = iterative_first_last(arr, n, x);
	cout << fl.first << ", " << fl.second << endl;
	return 0;
}