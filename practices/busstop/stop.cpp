#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, S, T;
    cin >> N >> M >> S >> T;

    vector<vector<int>> routes(M);
    vector<vector<int>> stop_to_routes(N + 1);

    for (int i = 0; i < M; i++) {
        int L;
        cin >> L;
        routes[i].resize(L);
        for (int j = 0; j < L; j++) {
            cin >> routes[i][j];
            stop_to_routes[routes[i][j]].push_back(i);
        }
    }

    queue<pair<int,int>> q;
    vector<bool> visited_stop(N + 1, false);
    vector<bool> visited_route(M, false);
    vector<int> dist(N + 1, INT_MAX);

    q.push({S, 0});
    visited_stop[S] = true;
    dist[S] = 0;

    while (!q.empty()) {
        auto [stop, d] = q.front();
        q.pop();

        if (stop == T) {
            cout << d / 2 << "\n";
            return 0;
        }

        for (int route : stop_to_routes[stop]) {
            if (visited_route[route]) continue;
            visited_route[route] = true;
            for (int next_stop : routes[route]) {
                if (!visited_stop[next_stop]) {
                    visited_stop[next_stop] = true;
                    q.push({next_stop, d + 1});
                }
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}
