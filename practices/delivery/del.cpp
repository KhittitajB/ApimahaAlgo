#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> bfs(int start_node, int N, const vector<vector<int>>& adj) {
    vector<int> dist(N + 1, -1);
    queue<int> q;

    q.push(start_node);
    dist[start_node] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj_all(n + 1);
    vector<vector<int>> adj_concrete(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj_all[a].push_back(b);
        adj_all[b].push_back(a);

        if (c == 1) {
            adj_concrete[a].push_back(b);
            adj_concrete[b].push_back(a);
        }
    }

    vector<int> ware;
    for (int j = 0; j < k; j++) {
        int smallk;
        cin >> smallk;
        ware.push_back(smallk);
    }

    int destination, concorno;
    cin >> destination >> concorno;

    int min_time = -1;

    if (concorno == 1) {

        for (int start_warehouse : ware) {
            auto temp_dist = bfs(start_warehouse, n, adj_concrete);

            int time_from_this_wh = temp_dist[destination];

            if (time_from_this_wh != -1) {
                if (min_time == -1 || time_from_this_wh < min_time) {
                    min_time = time_from_this_wh;
                }
            }
        }
    } else {

        for (int start_warehouse : ware) {
            auto temp_dist = bfs(start_warehouse, n, adj_all);

            int time_from_this_wh = temp_dist[destination];

            if (time_from_this_wh != -1) {
                if (min_time == -1 || time_from_this_wh < min_time) {
                    min_time = time_from_this_wh;
                }
            }
        }
    }

    cout << min_time << "\n";

    return 0;
}