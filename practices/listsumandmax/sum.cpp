#include <bits/stdc++.h>
using namespace std;

bool list_empty(const vector<int>& lst) {
    return lst.empty();
}

bool list_last(const vector<int>& lst, int index) {
    return index == (int)lst.size() - 1;
}

int recursive_sum(const vector<int>& lst, int index = 0) {
    if (list_empty(lst))
        return 0;
    if (list_last(lst, index))
        return lst[index];
    return lst[index] + recursive_sum(lst, index + 1);
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cout << recursive_sum(arr) << "\n";
    return 0;
}
