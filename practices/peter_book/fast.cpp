#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        if (!(cin >> n)) break;
        vector<int> seq(n);
        for (int i = 0; i < n; i++) cin >> seq[i];
        int goal;
        cin >> goal;

        sort(seq.begin(), seq.end());

        int left = 0, right = n - 1;
        int book1 = 0, book2 = 0;
        int bestDiff = INT_MAX;

        while (left < right) {
            int sum = seq[left] + seq[right];

            if (sum == goal) {
                int diff = seq[right] - seq[left];
                if (diff < bestDiff) {
                    bestDiff = diff;
                    book1 = seq[left];
                    book2 = seq[right];
                }
                left++;
                right--;
            } else if (sum < goal) {
                left++;
            } else {
                right--;
            }
        }

        cout << "Peter should buy books whose prices are "
             << book1 << " and " << book2 << ".\n\n";
    }

    return 0;
}
