#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ac = 0;

    vector<int> calendar(32, 0);

    for (int i = 0; i < n; i++) {
        int a, b, h;
        cin >> a >> b >> h;

        bool can = true;
        for (int day = a; day <= b; day++) {
            if (calendar[day] + h > 6) {
                can = false;
                break;
            }
        }
        if (can) {
            ac++;
            for (int day = a; day <= b; day++) {
                calendar[day] += h;
            }
        }
    }
    cout << ac;
}