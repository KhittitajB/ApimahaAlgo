#include <iostream>

using namespace std;

int main(){
    int day, exp;
    cin >> day;
    int sum = 0;

    for (int d = 1; d <= day; d++){
        cin >> exp;
        if (d%4 == 0){
            sum += exp;
        }
        sum += exp;

    }

    cout << sum;

    return 0;
}