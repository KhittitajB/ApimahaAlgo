#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph, int n) {
    vector<int> color(n, -1);
    queue<int> q;

    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) {
            color[start] = 0;
            q.push(start);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int nei : graph[node]) {
                    if (color[nei] == -1) {
                        color[nei] = 1 - color[node];
                        q.push(nei);
                    } else if (color[nei] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        int l;
        cin >> l;

        vector<vector<int>> graph(n);

        for (int i = 0; i < l; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        if (isBipartite(graph, n))
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }

    return 0;
}
