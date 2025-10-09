#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

bool canFill(const vector<int>& vessels, int m, long long capacity) {
    int containers = 1;
    long long current = 0;
    for (int milk : vessels) {
        if (milk > capacity)
            return false;
        if (current + milk <= capacity) {
            current += milk;
        } else {
            containers++;
            current = milk;
            if (containers > m)
                return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        vector<int> vessels(n);
        for (int i = 0; i < n; i++)
            cin >> vessels[i];

        long long left = *max_element(vessels.begin(), vessels.end());
        long long right = accumulate(vessels.begin(), vessels.end(), 0LL);
        long long answer = right;

        while (left <= right) {
            long long mid = (left + right) / 2;
            if (canFill(vessels, m, mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << answer << "\n";
    }
    return 0;
}
