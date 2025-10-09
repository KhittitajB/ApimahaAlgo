#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <sstream>
using namespace std;

int main() {
    string line;
    while (true) {
        int n;
        if (!getline(cin, line)) break;
        if (line.empty()) break;

        stringstream ss(line);
        ss >> n;

        vector<int> seq(n);
        getline(cin, line);
        stringstream ss2(line);
        for (int i = 0; i < n; i++) ss2 >> seq[i];

        int goal;
        cin >> goal;
        cin.ignore();

        string stock = "";
        int sub = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int res = seq[i] + seq[j];
                    if (res == goal) {
                        int ts = abs(seq[i] - seq[j]);
                        if (ts < sub) {
                            sub = ts;
                            int a = seq[i], b = seq[j];
                            if (a > b) swap(a, b);
                            stock = "Peter should buy books whose prices are " + to_string(a) + " and " + to_string(b) + ".";
                        }
                    }
                }
            }
        }

        cout << stock << "\n\n";
    }
    return 0;
}
