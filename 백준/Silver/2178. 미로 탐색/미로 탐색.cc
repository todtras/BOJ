#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
queue<pair<int, int>> q;
vector<vector<int>> graph;
vector<vector<int>> dist;

int main() {
    cin >> n >> m;

    dist.assign(n, vector<int>(m, -1));

    for (int i{0}; i < n; i++){
        vector<int> temp;

        for (int j{0}; j < m; j++) {
            char num;
            cin >> num;
            temp.push_back(num - '0');
        }

        graph.push_back(temp);
    }

    q.push({0,0});
    dist[0][0] = 1;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    while (!q.empty()) {
        auto current = q.front(); q.pop();

        int x = current.first;
        int y = current.second;

        if (x == n-1 && y == m-1) {
            cout << dist[x][y];
            return 0;
        }

        for (int i{0}; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (graph[nx][ny] == 0 || dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}
