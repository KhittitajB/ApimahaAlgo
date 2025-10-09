#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> zuma;
    vector<int> zn;
    vector<int> nn;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int ball;
        cin >> ball;
        zuma.push_back(ball);
    }

    for (int i = 0; i < n; i++) {
        zn.push_back(i + 1);
    }

    int ll = zn.size();

    for (int j = 0; j < m; j++) {
        int c, l;
        cin >> c >> l;

        nn.push_back(ll + j + 1);

        auto it = find(zn.begin(), zn.end(), l);
        if (it != zn.end()) {
            zn.insert(it + 1, nn[j]);
        }
    }

    for (int i = 0; i < zn.size(); i++) {
        cout << zn[i] << endl;
    }

    return 0;
}
