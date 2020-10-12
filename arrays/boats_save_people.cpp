#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: https://leetcode.com/problems/boats-to-save-people/ (MEDIUM level)

int min_boats_reqd(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int i = 0, j = people.size() - 1;
    int boats = 0;

    while (i <= j) {
        if (people[i] + people[j] <= limit) {
            boats++;
            i++;
            j--;
        } else {
            boats++;
            j--;
        }
    }

    return boats;
}

int main() {
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;

    cout << min_boats_reqd(people, limit) << endl;
    return 0;
}