#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adj;
public:
    Graph(int n) : n(n), adj(n + 1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool dfs(int node, vector<bool>& visited, vector<bool>& inStack) {
        visited[node] = true;
        inStack[node] = true;

        for (int nei : adj[node]) {
            if (!visited[nei] && dfs(nei, visited, inStack))
                return true;
            else if (inStack[nei])
                return true;
        }

        inStack[node] = false;
        return false;
    }

    bool hasCycle() {
        vector<bool> visited(n + 1, false);
        vector<bool> inStack(n + 1, false);

        for (int i = 1; i <= n; ++i)
            if (!visited[i] && dfs(i, visited, inStack))
                return true;

        return false;
    }
};

int main() {
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);

    if (g.hasCycle()) cout << "Cycle detected!\n";
    else cout << "No cycle.\n";
}
