#include <vector>
#include <map>
#include <iostream>

using namespace std;

int main() {
    int u, v;
    vector<vector<int>> adj_unweighted;
    vector<vector<pair<int, int>>> adj_weighted;


    // For an UNDIRECTED graph (like in your example)
    cin >> u >> v;
    adj_unweighted[u].push_back(v);
    adj_unweighted[v].push_back(u); // <-- You add this

    // For a DIRECTED graph
    cin >> u >> v;
    adj_unweighted[u].push_back(v);
    // <-- You simply DON'T add the reverse edge
    return 0;
}