#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;

  int count = 0;

  for (int i = 0; i < n; i++) {
    int a,b;
    cin >> a >> b;
    if (not (a > 400 or (b < 150 or b > 200))){
        // cout << "check" << endl;
        count += 1;
    }

  }
  cout << count << endl;
}