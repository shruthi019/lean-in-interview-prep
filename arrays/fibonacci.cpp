#include <iostream>
using namespace std;

// Problem: https://leetcode.com/problems/fibonacci-number/ (EASY level)

int fib(int N) {
    int a[31];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < 31; i++) {
        a[i] = a[i-1] + a[i-2];
    }
    return a[N];
}

int main() {
    int n;
    cin >> n;

    cout << fib(n) << endl;
    return 0;
}