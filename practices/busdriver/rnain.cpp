#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n, d, r;
    cin >> n >> d >> r;
    
    while (true) {
        if (n == 0 && d == 0 && r == 0) {
            break;
        }

        int pivm = 0;
        int pive = 0;

        for (int i = 0; i < n; i++) {
            int morn;
            cin >> morn;

            if (morn > pivm) {
                pivm = morn;
            }
        }

        for (int i = 0; i < n; i++) {
            int eve;
            cin >> eve;

            if (eve > pive) {
                pive = eve;
            }
        }

        int fee = (pive + pivm) - d;

        if (fee > 0) {
            cout << fee*r;
        }
        else {
            cout << 0;
        }

        cin >> n >> d >> r;
    }
    return 0;
}