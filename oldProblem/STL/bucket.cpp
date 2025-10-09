#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> buckets = {0, 0, 0, 0, 0};
    int n, water;
    int tank = 0;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> water;
        auto minwater = min_element(buckets.begin(), buckets.end());
        *minwater += water;

        if (*minwater >= 1000){
            tank += 1000;
            *minwater = 0;
        }
    }

    // for(int i: buckets){
    //     cout << i << " ";
    // }
    cout << tank;
}