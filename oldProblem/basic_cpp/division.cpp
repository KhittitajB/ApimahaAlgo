#include <iostream>

using namespace std;

int main(){

    int k;
    int pointX, pointY, x, y;

    while (true){
        // get num testcase
        cin >> k;
        if (k == 0){
            break;
        }

        // get division pt
        cin >> pointX;
        cin >> pointY;

        // get testcase
        for (int t = 0; t < k; t++){
            cin >> x;
            cin >> y;

            if (x == pointX or y == pointY){
                cout<< "divisa" << endl;
            }
            else {
                if (y > pointY){
                    cout << 'N';
                }
                else{
                    cout << "S";
                }

                if (x > pointX){
                    cout << "E" << endl;
                }
                else{
                    cout << "O" << endl;
                }
            }
        }

    }

    return 0;
}