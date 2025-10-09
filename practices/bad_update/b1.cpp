#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, int crash) {
    if (node == crash) return;
    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next] && next != crash)
            dfs(next, graph, visited, crash);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int maxFail = 0;

    for (int crash = 2; crash <= n; crash++) {
        vector<bool> visited(n + 1, false);
        dfs(1, graph, visited, crash);

        int failCount = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) failCount++;
        }

        if (failCount > maxFail)
            maxFail = failCount;
    }

    cout << maxFail << endl;
    return 0;
}
