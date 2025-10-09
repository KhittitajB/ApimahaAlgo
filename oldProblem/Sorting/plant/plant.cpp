#include <iostream>

using namespace std;

int main(){
    int r, c, n;
    cin >> r >> c >> n;

    int row[n];
    int col[n];

    for (int i = 0; i < n; i ++){
        int x, y;
        cin >> x >> y;

        row[i] = x;
        col[i] = y;
    }

    int mx = 0;
    int cur_max = 1;

    // //check row/ col
    // for(int i: row){
    //     cout << i <<' ';
    // }
    // cout << endl;
    // for(int i: col){
    //     cout << i <<' ';
    // }
    // cout << endl;


    for (int i = 0; i < n; i ++){
        int count = 0;
        for (int j = 0; j < n; j++){
            if (row[i] == row[j] or col[i] == col[j]){
                // cout << i+1 << ':' << j+1 << endl;
                count++;
            }
        }
        if (count > mx){
            mx = count;
            cur_max = i+1;
        }
    }

    cout << cur_max << ' ' << mx;





}