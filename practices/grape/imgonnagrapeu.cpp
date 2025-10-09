#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m, n || m) {
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> grid[i][j];

        int q;
        cin >> q;
        while (q--) {
            int L, U;
            cin >> L >> U;

            int best = 0;
            for (int i = 0; i < n; ++i) {
                // Binary search for first element >= L in row i
                int pos = lower_bound(grid[i].begin(), grid[i].end(), L) - grid[i].begin();

                // Try to expand square from here
                for (int size = best; i + size < n && pos + size < m; ++size) {
                    if (grid[i + size][pos + size] <= U)
                        best = size + 1;
                    else
                        break;
                }
            }

            cout << best << "\n";
        }
        cout << "-\n";
    }
    return 0;
}
