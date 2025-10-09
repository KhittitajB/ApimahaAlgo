#include <iostream>
// #include <algorithm>
// #include <vector>

using namespace std;

int main(){
    int n, s, t, t1;
    int speed = 0;
    int max_speed = 0;

    // vector<int> all_speed;


    cin >> n >> s;
    for (int i = 0; i < n; i ++){
        cin >> t;
        if (i == 0){
            t1 = t-1;
        }

        speed -= min(t - t1 - 1, speed);

        speed += s;

        t1 = t;

        // cout << speed << endl;

        if (max_speed < speed){
            max_speed = speed;
        }

    }

    cout << max_speed;
}