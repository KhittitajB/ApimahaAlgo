#include <bits/stdc++.h>
using namespace std;

bool list_empty(const vector<int>& lst) {
    return lst.empty();
}

bool list_last(const vector<int>& lst, int index) {
    return index == (int)lst.size() - 1;
}

int recursive_max(const vector<int>& lst, int index = 0) {
    if (list_empty(lst))
        return 0; // base case (though list will not be empty)
    if (list_last(lst, index))
        return lst[index];

    int next_max = recursive_max(lst, index + 1);
    if (lst[index] > next_max)
        return lst[index];
    else
        return next_max;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cout << recursive_max(arr) << "\n";
    return 0;
}
