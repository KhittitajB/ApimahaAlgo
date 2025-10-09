#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main(){
    int step;
    list<int> cookies;
    cin >> step;
    for(int i = 0; i < step; i++){
        int operation, k;
        cin >> operation;
        if (operation == 1){
            int c;
            // add cookies
            cin >> k;
            cin >> c;
            list<int>::iterator it = cookies.begin();
            // cout << k << cookies.size()<< endl;
            if (k <= cookies.size() and k > 0){
                
                advance(it, k);
                cookies.insert(it, c);
            }
            else if(k == 0){
                cookies.push_front(c);
            }
            else{
                cookies.push_back(c);
            }
            
        }
        else{
            cin >> k;
            if (!cookies.empty()){
                list<int>::iterator it = cookies.begin();
                if(k <= cookies.size()){
                    advance(it, k-1);
                    cookies.erase(it);
                }

            }
        }

        // cout << "---------" << endl << "## ";
        // for (int num: cookies){
        //     cout << num << " ";
        // }
        // cout << endl << "--------" << endl;
    }

    for (int cookie: cookies){
        cout << cookie << endl;
    }

    
}