#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q, caseNum = 1;

    while (cin >> n >> q, n || q) {
        vector<int> marbles(n);
        for (int i = 0; i < n; ++i) {
            cin >> marbles[i];
        }

        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << caseNum++ << ":\n";

        for (int i = 0; i < q; ++i) {
            int x;
            cin >> x;

            auto it = lower_bound(marbles.begin(), marbles.end(), x);

            if (it != marbles.end() && *it == x)
                cout << x << " found at " << (it - marbles.begin() + 1) << '\n';
            else
                cout << x << " not found\n";
        }
    }

    return 0;
}
