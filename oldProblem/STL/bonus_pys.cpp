#include <iostream>
#include <list>

using namespace std;

int main(){
    int n, m;
    list<int> line;
    
    cin >> n >> m;

    // add initial list
    for (int i = 0; i < n; i++){
        line.push_back(0);
    }

    auto angel = line.begin();
    // start loop
    for (int i = 0; i < m; i++){
        int action;
        cin >> action;
        if (action == 0){ // go to begin
            angel = line.begin();
        }
        else if (action == 1){ // go to next player
            if (angel != line.end()){
                angel++;
            }
        }
        else if (action == 2){ // insert new one
            angel++;
            line.insert(angel, 1, 0);
            angel--;
            angel--;
        }
        else if (action == 3){ // give score
            int x;
            cin >> x;
            *angel += x;
        }
    }

    for (int i: line){
        cout << i << " ";
    }

}