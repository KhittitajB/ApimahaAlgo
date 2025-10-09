#include <iostream>
#include <list>

using namespace std;

int main(){

    int m;
    list<int> queue;
    list<int> flavor;
    int fl[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    cin >> m;
    for (int i = 0; i < m; i++){
        int t, n, f;
        cin >> t;
        if (t==1) {
            // customer
            cin >> n;
            for (int j=0; j < n; j++){
                int c, f;
                cin >> c >> f;
                queue.push_back(c);
                flavor.push_back(f);
            }
        }
        else{
            cout << queue.front()<<endl;
            queue.pop_front();
            // add flavour
            int fn = flavor.front();
            flavor.pop_front();
            fl[fn-1]++;
        }
    }

    cout << queue.size() << endl;
    for (int i = 0; i < 20; i++){
        cout << fl[i] << " ";
    }

    return 0;
}