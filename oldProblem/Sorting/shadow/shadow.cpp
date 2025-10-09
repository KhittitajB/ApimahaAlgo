#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, l;
    int sha = 0;
    cin >> n >> l;

    int street[l];
    fill(street, street+l, 0);

    int b, s;
    for (int i = 0; i < n; i++){
        cin >> b >> s;
        for (int i = b; i <= b+s and i < l; i++){
            if (street[i] == 1){
                continue;
            }
            street[i] = 1;
            sha += 1;
        }
    }

    cout << sha << endl;

    return 0;


}