#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

// not working cuz need 2 adjacent term only

int main(){

    int n, x;
    while (cin >> n){
        int flipped = 0;
        list<int> l;
        for (int i = 0; i < n; i++){
            cin >> x;
            l.push_back(x);
        }
        //find max
        while (!l.empty()){
            auto maxi = max_element(l.begin(), l.end());
            // cout << ">>" << *maxi << endl;
            if (*maxi != l.back()){
                flipped++;
                *maxi = l.back();
            }
            l.pop_back();
        }

        cout << "Minimum exchange operations : " << flipped << endl;

    }
}