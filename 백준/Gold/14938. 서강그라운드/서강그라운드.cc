#include <bits/stdc++.h>
using namespace std;

void heapify_up(vector<pair<int, int>>& heap, int i){
    int p = i / 2;
    if(p == 0) return;

    if(heap[p].first > heap[i].first){
        swap(heap[i], heap[p]);
        heapify_up(heap, p);
    }
}

void heapify_down(vector<pair<int, int>>& heap, int i){
    int l = i * 2, r = i * 2 + 1, smallest = i;

    if(l < heap.size() && heap[smallest].first > heap[l].first) smallest = l;
    if(r < heap.size() && heap[smallest].first > heap[r].first) smallest = r;

    if(smallest != i){
        swap(heap[smallest], heap[i]);
        heapify_down(heap, smallest);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;
    vector<int> items(n + 1);
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
    vector<pair<int, int>> heap = {{-1, -1}};
    for(int i = 1;i <= n;i++) cin >> items[i];
    while(r--){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    for(int i = 1;i <= n;i++){
        heap.push_back({0, i});
        heapify_up(heap, heap.size() - 1);
        dist[i][i] = 0;

        while(heap.size() > 1){
            auto [cost, now] = heap[1];
            heap[1] = heap[heap.size() - 1];
            heap.pop_back();
            heapify_down(heap, 1);

            if(cost > dist[i][now]) continue;

            for(auto [weight, next] : adj[now]){
                if(dist[i][next] > cost + weight){
                    dist[i][next] = cost + weight;
                    heap.push_back({cost + weight, next});
                    heapify_up(heap, heap.size() - 1);
                }
            }

        }
    }

    int max_num = 0;
    for(int start = 1;start <= n;start++){
        int temp = 0;
        for(int goal = 1;goal <= n;goal++){
            if(dist[start][goal] <= m){
                temp += items[goal];
            }
        }
        max_num = max(temp, max_num);
    }

    cout << max_num;

    return 0;
}