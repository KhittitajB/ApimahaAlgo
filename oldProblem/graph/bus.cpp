#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> H(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    for (int query = 0; query < Q; query++) {
        int S, T, P;
        cin >> S >> T >> P;

        vector<bool> visited(N + 1, false);
        queue<int> q;
        q.push(S);
        visited[S] = true;

        bool canReach = false;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == T) {
                canReach = true;
                break;
            }

            for (int v : adj[u]) {
                if (!visited[v]) {
                    // downhill or within power limit uphill
                    if (H[v] <= H[u] || H[v] - H[u] <= P) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        cout << (canReach ? "yes" : "no") << '\n';
    }

    return 0;
}
