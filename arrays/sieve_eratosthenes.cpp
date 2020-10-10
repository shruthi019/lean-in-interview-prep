#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// Problem: Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.

vector<int> sieve_eratosthenes(int n) {
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p < n; p++) {
        if (prime[p]) {
            for (int i = p * p; i < n; i += p) {
                prime[i] = false;
            }
        }
    }

    vector<int> all_primes;

    for (int i = 2; i < n; i++) {
        if(prime[i]) {
            all_primes.push_back(i);
        }
    }

    return all_primes;
}

int main() {
    int n;
    cin >> n;

    vector<int> primes = sieve_eratosthenes(n);

    for (int p: primes) {
        cout << p << ", ";
    }

    cout << endl;

    return 0;
}