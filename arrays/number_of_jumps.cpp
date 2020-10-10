#include <iostream>
using namespace std;

// Problem: Given an integers X. The task is to find the number of jumps to reach a point X in the number line starting from zero.

int sum(int n) {
    return (n * (n + 1)) / 2;
}

int no_of_jumps(int n) {
    n = abs(n);

    int jumps = 0;

    while (sum(jumps) < n || (sum(jumps) - n) & 1) {
        jumps++;
    }

    return jumps;
}

int main() {
    int n;
    cin >> n;

    cout << no_of_jumps(n) << endl; 
    return 0;
}