#include <iostream>
#include <list>

using namespace std;


int main(){
    int n, k;
    vector<int> rocks;
    auto look = rocks.end();
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        // rocks.push_back(r);

        if (i < k-1) {
            rocks.push_back(r);
            continue;
        }

        //check
        look = rocks.end();
        look--; //get last order
        if (k == 2){
            if (*look == r){
                rocks.pop_back();
                continue;
            }
        }
        else if (k == 3){
            if (*look == r){
                look--;
                if (*look == r){
                    rocks.pop_back();
                    rocks.pop_back();
                    continue;
                }
            }
        }
        rocks.push_back(r);
    }

    cout << rocks.size();
  return 0;

}