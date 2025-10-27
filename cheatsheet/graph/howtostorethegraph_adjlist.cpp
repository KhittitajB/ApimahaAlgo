#include <vector>
#include <map>

using namespace std;

vector<vector<int>> adj_unweighted;
vector<vector<pair<int, int>>> adj_weighted;

// --- How to read N nodes and M edges ---
// int N, M;
// cin >> N >> M;
// adj_unweighted.resize(N + 1); // +1 for 1-based indexing
// for (int i = 0; i < M; ++i) {
//     int u, v;
//     cin >> u >> v;
//     adj_unweighted[u].push_back(v);
//     adj_unweighted[v].push_back(u); // For undirected
// }