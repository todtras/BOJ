#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, v;
vector<vector<int>> adj;

void dfs(int start) {
    stack<int> s;
    vector<int> visited(n+1, 0);

    s.push(start);

    while (!s.empty()) {
        int cur = s.top(); s.pop();

        if (visited[cur]) continue;

        visited[cur] = 1;
        cout << cur << " ";

        for (int i = adj[cur].size()-1; i >= 0; i-- ) {
            int next = adj[cur][i];
            if (!visited[next]) {
                s.push(next);
            }
        }
    }
}

void bfs(int start) {
    queue<int> q;
    vector<int> visited(n+1, 0);

    q.push(start);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (visited[cur]) continue;

        visited[cur] = 1;
        cout << cur << " ";

        for (int next : adj[cur]) {
            if (!visited[next]) {
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n >> m >> v;

    adj.resize(n+1);

    for (int i{0}; i < m; i++) {
        int f, s;
        cin >> f >> s;

        adj[f].push_back(s);
        adj[s].push_back(f);
    }

    for (auto& v : adj) {
        sort(v.begin(), v.end());
    }

    dfs(v);
    cout << '\n';
    bfs(v);
}
