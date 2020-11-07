#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/rabbits-in-forest/ (MEDIUM level)

int numRabbits(vector<int>& answers) {
    unordered_map<int, int> m;
    
    for (int x: answers) {
        m[x]++;
    }
    
    int rabbits = 0;
    
    for (auto p: m) {
        rabbits += ceil(p.second / float(p.first + 1)) * (p.first + 1);
    }

    return rabbits;
}

int main() {
	vector<int> v = {1, 1, 2};
	cout << numRabbits(v) << endl;
	return 0;
}