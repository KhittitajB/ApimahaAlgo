#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool in_bounds(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    visited.assign(n, vector<bool>(m, false));

    int top_quality = 0, good_quality = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && grid[i][j] != '#') {
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;

                bool has_forest = false, has_mineral = false;
                int size = 0;

                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    size++;

                    if (grid[x][y] == '*') has_forest = true;
                    if (grid[x][y] == '$') has_mineral = true;

                    for (int d = 0; d < 4; ++d) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (in_bounds(nx, ny) && !visited[nx][ny] && grid[nx][ny] != '#') {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }

                if (has_forest && has_mineral)
                    top_quality += size;
                else if (has_forest || has_mineral)
                    good_quality += size;
            }
        }
    }

    cout << top_quality << " " << good_quality << endl;
    return 0;
}
