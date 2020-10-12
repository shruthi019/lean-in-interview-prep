#include <iostream>
#include <vector>
using namespace std;

vector<int> squares(vector<int> v) {
    int n = v.size();
    int j = 0;
    while (j < n && v[j] < 0) {
        j++;
    }

    int i = j - 1;

    vector<int> sq;

    while (i >= 0 && j < n) {
        if (v[i] * v[i] < v[j] * v[j]) {
            sq.push_back(v[i] * v[i]);
            i--;
        } else {
            sq.push_back(v[j] * v[j]);
            j++;
        }
    }

    while (i >= 0) {
        sq.push_back(v[i] * v[i]);
        i--;
    }

    while (j < n) {
        sq.push_back(v[j] * v[j]);
        j++;
    }

    return sq;
}

int main() {
    vector<int> v = {-4, -2, -1, 3, 5, 7};
    vector<int> sq = squares(v);

    for (int x: sq) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}