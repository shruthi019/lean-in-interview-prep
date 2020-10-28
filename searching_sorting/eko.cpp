#include <iostream>
using namespace std;
#define ll long long 

int main() {
	ll n, m;
    cin >> n >> m;
	ll heights[n];
	ll maxx = -1;

	for (ll i = 0; i < n; i++) {
		cin >> heights[i];
		maxx = max(maxx, heights[i]);
	}

	ll lo = 0, hi = maxx, mid, cut = 0, h = 0;

	while (lo <= hi) {
		mid = (lo + hi) / 2;
		cut = 0;
		for (ll i = 0; i < n; i++) {
			if (heights[i] - mid > 0) {
				cut += heights[i] - mid;
			}
		}
        
        if (cut == m) {
            h = mid;
            break;
        } else if (cut < m) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
            if (mid > h) {
                h = mid;
            }
        }
	}
    cout << h << endl;
	return 0;
}
