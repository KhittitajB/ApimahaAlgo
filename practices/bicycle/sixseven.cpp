#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // For std::max

using namespace std;

// A structure to store the master list of all edges
struct Edge {
    int u, v, difficulty;
};

/**
 * Standard BFS function.
 * Finds the shortest path (in number of edges) from 'start_node'
 * to all other nodes in the given adjacency list 'adj'.
 * Returns a vector of distances. Unreachable nodes are -1.
 */
vector<int> bfs(int start_node, int N, const vector<vector<int>>& adj) {
    vector<int> dist(N + 1, -1);
    queue<int> q;

    q.push(start_node);
    dist[start_node] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) { // If not visited
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    // 1. Store all edges in a master list
    vector<Edge> all_edges;
    for (int i = 0; i < M; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        all_edges.push_back({u, v, d});
    }

    // 2. Loop for each of the Q queries
    for (int q_num = 0; q_num < Q; ++q_num) {
        int max_difficulty;
        cin >> max_difficulty;

        // 3a. Build the temporary graph for this query
        vector<vector<int>> adj(N + 1);
        for (const auto& edge : all_edges) {
            if (edge.difficulty <= max_difficulty) {
                adj[edge.u].push_back(edge.v);
                adj[edge.v].push_back(edge.u);
            }
        }

        // 3b. Run a single BFS from node 1
        vector<int> distances = bfs(1, N, adj);

        // 3c. Find the maximum distance in the result
        int max_shortest_path = 0;
        for (int i = 1; i <= N; ++i) {
            if (distances[i] > max_shortest_path) {
                max_shortest_path = distances[i];
            }
        }

        // 3d. Output the answer for this query
        cout << max_shortest_path << "\n";
    }

    return 0;
}