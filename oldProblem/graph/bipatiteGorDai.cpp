#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph, int n) {
    vector<int> color(n + 1, -1);
    for (int start = 1; start <= n; start++) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;
            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int nei : graph[node]) {
                    if (color[nei] == -1) {
                        color[nei] = 1 - color[node];
                        q.push(nei);
                    } else if (color[nei] == color[node])
                        return false;
                }
            }
        }
    }
    return true;
}

string isBipartiteGraph() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (isBipartite(graph, n)) {
        return "yes";
    } else {
        return "no";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << isBipartiteGraph() << endl;
    }
    return 0;
}