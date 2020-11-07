#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/array-of-doubled-pairs/ (MEDIUM level)

static bool comp(int x, int y) {
    return abs(x) < abs(y);
}

bool canReorderDoubled(vector<int>& A) {
    unordered_map<int, int> m;
    
    for (int x: A) {
        m[x]++;
    }
    
    sort(A.begin(), A.end(), comp);

    for (int x: A) {
        if (m[x] > 0) {
            auto c = m.find(x * 2);
            if (c != m.end()) {
                if ((*c).second <= 0) {
                    return false;
                }
                m[x] -= 1;
                (*c).second--;
            }
        }
    }
    
    for (auto p: m) {
        if (p.second != 0) {
            return false;
        }
    }
    return true;
}

int main() {
	vector<int> v = {3, 1, 3, 6};
	cout << canReorderDoubled(v) << endl;
	return 0;
}
