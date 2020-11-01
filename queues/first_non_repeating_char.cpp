#include <iostream>
#include <queue>
using namespace std;

// Problem: https://www.geeksforgeeks.org/queue-based-approach-for-first-non-repeating-character-in-a-stream/

int main() {
    char x;
    cin >> x;
    int freq[26] = {0};
    queue<char> q;

    while (x != '.') {
        freq[x - 'a'] += 1;
        q.push(x);

        while (!q.empty()) {
            if (freq[q.front() - 'a'] > 1) {
                q.pop();
            } else {
                cout << q.front() << endl;
                break;
            }
        }

        if (q.empty()) {
            cout << -1 << endl;
        }

        cin >> x;
    }
    
    return 0;
}