#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 100010;

int arr[MAX_N];

vector<int> v;

int main(){
    //ios:: sync_with_studio(false)
    //cin.tie(NULL);

    int n, x, k;

    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        cin >> x;
        // arr[i] = x; //(if using arr)
        v.push_back(x);
    }

    // sort(arr, arr+n); // arr is the first pointer (if using arr)
    sort(v.begin(), v.end());

    int j = k-1;
    while (j < n){
        cout << v[j] << endl;
        j += k;
    }


}