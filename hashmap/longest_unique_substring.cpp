#include <iostream>
#include <unordered_set>
using namespace std;

int longestUniqueSubstring(string s) {
    unordered_set<char> unique;

    int i = 0, j = 0;
    int maxLength = 0;
    int n = s.length();

    while (i < n && j < n) {
        if (unique.find(s[j]) == unique.end()) {
            unique.insert(s[j]);
            j++;
            maxLength = max(maxLength, j - i);
        } else {
            unique.erase(s[i]);
            i++;
        }
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << longestUniqueSubstring(s) << endl;
    return 0;
}