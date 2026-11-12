#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int from[10000], to[10000];
vector<vector<int>> adj;
int max_num = 0, connected_cnt = 0;
vector<bool> visited;

void dfs(int vertex){ 
    max_num = max(max_num, connected_cnt);
    for(int nv : adj[vertex]){
        if(visited[nv]) continue;
        visited[nv] = true;
        connected_cnt++;
        dfs(nv);
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
        adj[from[i]].push_back(to[i]);
        adj[to[i]].push_back(from[i]);
    }
    visited.resize(n + 1, false);
    visited[1] = true;
    dfs(1);

    cout << max_num;

    return 0;
}
