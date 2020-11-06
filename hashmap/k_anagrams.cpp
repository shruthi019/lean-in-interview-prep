#include <iostream>
#include <unordered_map>
using namespace std;

// Problem: https://www.geeksforgeeks.org/check-two-strings-k-anagrams-not/

bool k_anagrams(string s1, string s2, int k) {
	if (s1.length() != s2.length()) {
		return false;
	}

	unordered_map<char, int> m;
	int l = s1.length();

	for (int i = 0; i < l; i++) {
		m[s1[i]]++;
	}

	int count = 0;

	for (int i = 0; i < l; i++) {
		if (m[s2[i]] > 0) {
			m[s2[i]]--;
		} else {
			count++;
		}

		if (count > k) {
			return false;
		}
	}

	return true;
}

int main() {
	string s1 = "anagram";
	string s2 = "grammar";
	int k = 3;

	cout << k_anagrams(s1, s2, k) << endl;
	return 0;
}