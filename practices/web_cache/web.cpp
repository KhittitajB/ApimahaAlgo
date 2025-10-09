#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> mxl;
    int miss = 0;

    for (int i = 0; i < m; i++) {
        int cac;
        cin >> cac;

        if (find(mxl.begin(), mxl.end(), cac) != mxl.end()) {
            continue;
        }
        else {
            if (mxl.size() < n) {
                mxl.push_back(cac);
                miss++;
            } else {
                mxl.erase(mxl.begin());
                mxl.push_back(cac);
                miss++;
            }
        }
    }

    cout << miss;
    return 0;
}
