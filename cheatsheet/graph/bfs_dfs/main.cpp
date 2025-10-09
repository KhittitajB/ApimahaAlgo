#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int start, vector<vector<int>>& graph, int n) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    vector<int> order;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);
        for (int nei : graph[node]) {
            if (!visited[nei]) {
                visited[nei] = true;
                q.push(nei);
            }
        }
    }
    return order;
}

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& order) {
    visited[node] = true;
    order.push_back(node);
    for (int nei : graph[node])
        if (!visited[nei])
            dfs(nei, graph, visited, order);
}
