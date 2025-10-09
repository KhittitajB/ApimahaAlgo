#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// const int MAX_N = 100010;
// int arr[MAX_N];

vector<pair<int, int>> v;

int main()
{
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);
  int n, x, y;
  cin >> n;

  for(int i = 0; i< n; i++) {
    cin >> x;
    //arr[i] = x;
    bool found = false;
    for (int j = 0; j < v.size(); j++){
        if (v[j].second == x){
            // cout << '\n' << k.second << "====" << k.first;
            v[j].first = v[j].first - 1;
            found = true;
            break;
        }
    }
    if (!found){
        v.push_back({-1, x});
    }
  }

  //sort(arr, arr+n);


//   int j = 0;
//   while(j < n){
//     cout << v[j].first << " " << v[j].second << endl;
//     j++;
//   }

  for (auto k: v){
    // cout << k.first << " " << k.second << endl;
    cout << k.second << endl;
  }

}