#include <iostream>
#include <unordered_map>
using namespace std;

// Problem: https://www.geeksforgeeks.org/check-anagram-string-palindrome-not/

bool anagram_possible(string s) {
	unordered_map<char, int> m;

	for (int i = 0; i < s.length(); i++) {
		m[s[i]]++;
	}

	int odd_count = 0;

	for (auto p: m) {
		if (p.second % 2 == 1) {
			odd_count++;
		}
	}

	return odd_count <= 1;
}

int main() {
	string s = "hellohello";
	cout << anagram_possible(s) << endl;
	return 0;
}