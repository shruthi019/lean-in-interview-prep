#include <iostream>
#include <algorithm>
using namespace std;

/* 
Problem: Given arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits.
We are given two arrays which represent arrival and departure times of trains that stop.
https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
*/

int min_platforms(int* arr, int* dep, int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);

    int i = 1, j = 0;
    int platforms = 1;
    int minimum_platforms = 1;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }
        minimum_platforms = max(minimum_platforms, platforms);
    }

    return minimum_platforms;
}

int main() {
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    cout << "Min platforms = " << min_platforms(arr, dep, n) << endl;
    return 0;
}