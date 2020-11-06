#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Problem: https://leetcode.com/problems/group-anagrams/ (MEDIUM level)

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string> > m;
    
    for (string s: strs) {
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        if (m.find(sorted_s) == m.end()) {
            m.insert({sorted_s, {s}});
        } else {
            m[sorted_s].push_back(s);
        } 
    }
    
    vector<vector<string> > ans;
    
    for (auto p: m) {
        vector<string> group;
        for (string s: p.second) {
            group.push_back(s);
        }
        ans.push_back(group);
    }
    
    return ans; 
}

int main() {
	vector<string> v = {"eat","tea","tan","ate","nat","bat"};
	vector<vector<string> > grouped_anagrams = groupAnagrams(v);

	for (auto v: grouped_anagrams) {
		for (string s: v) {
			cout << s << ", ";
		}
		cout << endl;
	}

	return 0;
}