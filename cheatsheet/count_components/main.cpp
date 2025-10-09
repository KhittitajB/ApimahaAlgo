#include <bits/stdc++.h>
using namespace std;

void dfs_comp(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int nei : graph[node])
        if (!visited[nei])
            dfs_comp(nei, graph, visited);
}

int countComponents(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n + 1, false);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs_comp(i, graph, visited);
            count++;
        }
    }
    return count;
}
