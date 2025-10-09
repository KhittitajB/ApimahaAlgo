#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> vl;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vl.push_back(x-y);
    }

    sort(vl.begin(), vl.end(), greater<>());

//    for (int vl : vl) {
//        cout << vl << " ";
//    }

    for (int j : vl) {
        if (j <= 0 && k > 0) {
            vl.pop_back();
            k--;
        }
    }

    auto result = reduce(vl.begin(), vl.end());
    cout << result;
    return 0;
}