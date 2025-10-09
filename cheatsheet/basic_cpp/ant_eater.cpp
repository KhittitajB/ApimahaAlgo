#include <iostream>

using namespace std;

int main(){
    int day, given, food;
    bool full = false;
    bool ate = false;
    int sum = 0;

    // get day
    cin >> day;

    //day loop
    for(int d = 0; d < day; d++){

        ate = false;
        // get food
        cin >> given;

        food = min(1000, given);

        if (!full){
            sum += food;
            ate = true;
        }

        if (food == 1000 and ate){
            full = true;
        }
        else{
            full = false;
        }

    }

    cout << '\n' << sum;

    return 0;

}