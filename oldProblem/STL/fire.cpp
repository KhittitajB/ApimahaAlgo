#include <iostream>
using namespace std;

//only 50% pass

int main(){

    int n, k;
    cin >> n >> k;
    int x, y;
    int f[n][n]; // fire map
    // set all to false
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j ++){
            f[i][j] = 0;
        }
    }
    // get the fire
    for(int i = 0; i < k; i ++){
        cin >> x >> y;
        f[x-1][y-1] = 1;
    }

    int t = 0; int l = (n*n)-k;

    while (l > 0){ // while there still space left

        // check the fucking field
        // for (int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j ++){
        //         cout << f[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "----------------" << endl;

        for (int i = 0; i < n; i++){
            for(int j = 0; j < n; j ++){
                // cout << "RUNNING " << t << endl;
                if (f[i][j] == 0){
                    //check all the beside block
                    // top
                    if (i != 0 and f[i-1][j] == t+1){
                        f[i][j] = t+1+1;
                        l --;
                    }
                    // bottom
                    else if (i != n-1 and f[i+1][j] == t+1){
                        f[i][j] = t+1+1;
                        l --;
                    }
                    // left? idk i cant sep left-right but i would say front
                    else if (j != 0 and f[i][j-1] == t+1){
                        f[i][j] = t+1+1;
                        l --;
                    }
                    // right idk i cant sep left-right but i would say back
                    else if (j != n-1 and f[i][j+1] == t+1){
                        f[i][j] = t+1+1;
                        l --;
                    }
                }
            }
        }


        t++;

    }

    cout << t; // -1 bc one for check if no one left, one for adding of that one



}