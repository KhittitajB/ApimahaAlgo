#include <iostream>
#include <list>

// zamoo zuma not zamoo ez cuz that not ez

using namespace std;

int main(){
    int n;
    list<int> zamoo;
    cin >> n;
    auto p = zamoo.begin();
    for (int i = 0; i < n; i++){
        int side, num;
        bool dl = false;
        cin >> side >> num;
        if (side == 0){ //front
            //check first
            for(auto j = zamoo.end(); j != zamoo.begin(); j--){
                if (num == *j){
                    dl = true;
                    p = j;
                    break;
                }
            }
            if (dl){
                zamoo.erase(zamoo.begin(), ++p);
            }
            else{
                zamoo.push_front(num);
            }
        }

        else if (side == 1){ //back
            //check last
            for(auto j = zamoo.begin(); j != zamoo.end(); j++){
                if (num == *j){
                    dl = true;
                    p = j;
                    break;
                }
            }
            if (dl){
                zamoo.erase(p, zamoo.end());
            }
            else{
                zamoo.push_back(num);
            }
        }

        for(int z: zamoo){
            cout << z <<" ";
        }
        cout << endl;
    }
    cout << zamoo.size();
}