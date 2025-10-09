#include <iostream>

using namespace std;

int Odd_one_out(const int array[], const int size){

    for (int i = 0 ; i < size ; i++) {
        int count = 0;
        for (int j = 0 ; j < size ; j++) {
            if (array[i] == array[j]) {
                count++;
            }
        }
        if (count == 1) {
            return i;
        }
    }
    return -1;
}

int main(){
    int n, num;
    cin >> n;
    int table[n][n];
    int horizon[n], vertical[n];

    for (int i = 0; i < n; i++){
        horizon[i] = 0;
        vertical[i] = 0;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> num;
            table[i][j] = num;
            vertical[j] += num;
            horizon[i] += num;
        }
    }
    int h = Odd_one_out(horizon, n);
    int v = Odd_one_out(vertical, n);
    cout << table[h][v];
}