#include <iostream>

using namespace std;


const int MAX_N = 10010; // max n

int x[MAX_N]; // if the array is big, make it global var

int main(){

    int a, n;

    n = 0;
    while (cin >> a){
        //using insertion sort
        x[n] = a;
        n++;
        int i = n-1; // current guy at x[i]

        //insertion sort
        while((i > 0) && (x[i-1] > x[i])){
            // add it at the last, if the last is less then before, move up until cant
            int tmp = x[i];
            x[i] = x [i-1];
            x[i-1] = tmp;
            i--;
        }

        if (n%2){ // odd
            cout << x[n/2] << endl;
        }
        else{
            cout << ((x[n/2] + x[(n/2)-1])/2) << endl;
        }

    }


}