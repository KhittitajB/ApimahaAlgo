#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>       // For the BFS queue
#include <algorithm>   // For std::max

// Use the namespace as requested
using namespace std;

/**
 * @struct Edge
 * @brief Stores a single edge and its difficulty.
 * We need this to store all M edges, since each query
 * will filter them differently.
 */
struct Edge {
    int u, v;       // The two nodes
    int difficulty; // The edge's difficulty
};

int main() {
    // 1. Read N, M, Q
    int N, M, Q;
    cin >> N >> M >> Q;

    // 2. Store all M edges in a vector
    // We can't build the graph yet, as we need to
    // filter by difficulty for each query.
    vector<Edge> all_edges;
    for (int i = 0; i < M; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        all_edges.push_back({u, v, d});
    }

    // 3. Process each of the Q queries
    for (int q_idx = 0; q_idx < Q; ++q_idx) {
        int B_i; // The max difficulty for this group
        cin >> B_i;

        // 4. Build the filtered graph (adjacency list)
        // We use the unordered_map, as demonstrated in our shortcut.
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : all_edges) {
            // Only add edges that the group can use [cite: 7]
            if (edge.difficulty <= B_i) {
                // Add the undirected edge
                graph[edge.u].push_back(edge.v);
                graph[edge.v].push_back(edge.u);
            }
        }

        // 5. Run BFS from node 1 to find shortest paths 
        queue<int> q;
        
        // 'distances' vector stores shortest path length from 1.
        // We use N+1 for 1-based indexing (nodes 1 to N).
        // -1 means "not visited" or "unreachable".
        vector<int> distances(N + 1, -1);

        // Start BFS from node 1 (the center) [cite: 4]
        q.push(1);
        distances[1] = 0;

        int max_shortest_path = 0; // The answer for this query

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Check if node u is in the (filtered) graph.
            // .count() checks if the key 'u' exists in the map.
            if (graph.count(u)) { 
                // Look at all neighbors 'v' of 'u'
                for (int v : graph[u]) {
                    if (distances[v] == -1) { // If 'v' is not visited
                        distances[v] = distances[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        // 6. Find the "longest shortest path" 
        // Iterate through all nodes 's' from 1 to N
        for (int s = 1; s <= N; ++s) {
            // We only care about nodes that are reachable from 1 [cite: 11]
            // (i.e., their distance is not -1)
            if (distances[s] != -1) {
                max_shortest_path = max(max_shortest_path, distances[s]);
            }
        }

        // 7. Output the answer for this query [cite: 64]
        cout << max_shortest_path << endl;
    }

    return 0;
}