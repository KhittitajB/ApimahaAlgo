#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(int n, int start, vector<vector<pair<int,int>>>& graph) {
    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, node] = pq.top(); pq.pop();
        if (d > dist[node]) continue;
        for (auto [nei, w] : graph[node]) {
            if (dist[nei] > d + w) {
                dist[nei] = d + w;
                pq.push({dist[nei], nei});
            }
        }
    }
    return dist;
}
