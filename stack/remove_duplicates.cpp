#include <iostream>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/remove-duplicate-letters/ (MEDIUM level)

string removeDuplicateLetters(string s) {
    string result = "";
    vector<bool> visited(26);
    vector<int> count(26);

    for (auto x: visited) {
        x = false;
    }

    for (auto c: count) {
        c = 0;
    }

    for (auto character: s) {
        count[character - 'a']++;
    }

    for (auto ch: s) {
        int idx = ch - 'a';

        count[idx]--;

        if (visited[idx]) {
            continue;
        }

        while (!result.empty() && result.back() > ch && count[result.back() - 'a']) {
            visited[result.back() - 'a'] = false;
            result.pop_back();
        }

        result += ch;
        visited[idx] = true;
    }

    return result;
}

int main() {
    cout << removeDuplicateLetters("bacdeabc");
    return 0;
}
