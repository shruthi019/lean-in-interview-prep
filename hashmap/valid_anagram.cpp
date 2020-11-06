#include <iostream>
#include <unordered_map>
using namespace std;

// Problem: https://leetcode.com/problems/valid-anagram/

bool isAnagram(string s, string t) {
    unordered_map<char, int> m;

    for (int i = 0; i < s.length(); i++) {
        m[s[i]]++;
    }

    for (int i = 0; i < t.length(); i++) {
        if (m.find(t[i]) == m.end()) {
            return false;
        }

        m[t[i]]--;
    }
    
    for (auto pair: m) {
        if (pair.second != 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
	string s, t;
	
	s = "anagram";
	t = "nagrama";

	cout << isAnagram(s, t) << endl;
	return 0;
}