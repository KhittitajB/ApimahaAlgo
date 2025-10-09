#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adj;
public:
    Graph(int n) : n(n), adj(n + 1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool dfs(int node, int parent, vector<bool>& visited) {
        visited[node] = true;
        for (int nei : adj[node]) {
            if (!visited[nei]) {
                if (dfs(nei, node, visited)) return true;
            }
            else if (nei != parent) {
                return true;
            }
        }
        return false;
    }

    bool hasCycle() {
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                if (dfs(i, -1, visited)) return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    if (g.hasCycle()) cout << "Cycle detected!\n";
    else cout << "No cycle.\n";
}
