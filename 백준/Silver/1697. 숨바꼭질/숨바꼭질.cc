#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
queue<int> q;
vector<int> dist;

int main() {
    cin >> n >> m;

    dist.assign(100001, -1);

    q.push(n);
    dist[n] = 0;

    while (!q.empty()) {
        int current = q.front(); q.pop();

        if (current == m) {
            cout << dist[current];
            return 0;
        }

        int dx[3] = {-1, 1, current};

        for (int i{0}; i < 3; i++) {
            int nx = current + dx[i];

            if (nx < 0 || nx > 100000) continue;
            if (dist[nx] != -1) continue;

            dist[nx] = dist[current] + 1;
            q.push(nx);
        }
    }
}
