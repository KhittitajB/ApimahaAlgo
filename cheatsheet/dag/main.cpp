#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<vector<int>>& graph, int n) {
    vector<int> indeg(n + 1, 0);
    for (int u = 1; u <= n; u++)
        for (int v : graph[u])
            indeg[v]++;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : graph[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }
    return order;
}
