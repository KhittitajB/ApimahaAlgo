#include <iostream>
#include <vector>
#include <queue>
#include <map> // Or use vector<int> H(N+1)

using namespace std;

// This structure holds a route.
struct Route {
    int u, v;
};

// Helper function to run BFS for a single query.
bool can_reach(int start_node, int end_node, int N,
               const vector<vector<int>>& adj) {

    queue<int> q;
    vector<bool> visited(N + 1, false);

    q.push(start_node);
    visited[start_node] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == end_node) {
            return true; // Found the target!
        }

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return false; // Traversal finished without finding the target
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    // Store heights (using 1-based indexing)
    vector<int> heights(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> heights[i];
    }

    // Store all routes to check later
    vector<Route> all_routes(M);
    for (int i = 0; i < M; ++i) {
        cin >> all_routes[i].u >> all_routes[i].v;
    }

    // Process each query
    for (int j = 0; j < Q; ++j) {
        int S, T, P;
        cin >> S >> T >> P;

        // 1. Build the directed graph for this query's power P
        vector<vector<int>> adj(N + 1);
        for (const auto& route : all_routes) {
            int u = route.u;
            int v = route.v;

            // Check u -> v
            if (heights[v] - heights[u] <= P) {
                adj[u].push_back(v);
            }
            // Check v -> u
            if (heights[u] - heights[v] <= P) {
                adj[v].push_back(u);
            }
        }

        // 2. Run BFS/DFS to find the path
        if (can_reach(S, T, N, adj)) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }

    return 0;
}