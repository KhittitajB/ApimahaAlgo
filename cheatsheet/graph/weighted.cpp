#include <vector>
#include <iostream>

using namespace std;

// This is a common shortcut for "pair of integers"
typedef pair<int, int> pii;

int main() {
    int N, M;
    cin >> N >> M;

    // The adjacency list is now a vector of vectors of PAIRS
    // adj[u] = { {v1, w1}, {v2, w2}, ... }
    vector<vector<pii>> adj_weighted(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // Read the weight

        // Add the edge {neighbor, weight}
        adj_weighted[u].push_back({v, w});

        // If it's an UNDIRECTED weighted graph, add the reverse edge
        adj_weighted[v].push_back({u, w});
    }

    // Now, pass this 'adj_weighted' to Dijkstra's
    // vector<ll> dists = dijkstra(1, N, adj_weighted);

    return 0;
}