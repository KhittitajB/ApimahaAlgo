#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPathUnweighted(vector<vector<int>>& graph, int start, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int nei : graph[node]) {
            if (dist[nei] == -1) {
                dist[nei] = dist[node] + 1;
                q.push(nei);
            }
        }
    }
    return dist;
}
