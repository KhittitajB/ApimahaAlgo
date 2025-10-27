#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;

        vector<int> pcs;
        vector<int> ccs;

        for (int j = 0; j < p; j++) {
            int proc;
            cin >> proc;

            pcs.push_back(proc);
        }

        for (int k = 0; k < p; k++) {
            int con;
            cin >> con;

            ccs.push_back(con);
        }

        int lowest = 0;
        int gugleadmain = 0;

        sort(pcs.begin(), pcs.end());

        for (int x = 0; x < pcs.size(); x++) {
//
            int piv = pcs[x];
            int mt = 0;
            mt += pcs.size()-x-1;

            for (auto v : ccs) {
                if (v < piv) {
                    mt++;
                }
            }

            if (lowest == 0) {
                gugleadmain = mt;
                lowest = piv;
            }
            else if (mt < gugleadmain) {
                gugleadmain = mt;
                lowest = piv;
            }
//
            //cout << lowest << " " << gugleadmain << "\n";//
        }

        cout << lowest << " " << gugleadmain << "\n";//
    }
    return 0;
}