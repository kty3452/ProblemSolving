#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int coin[100];
int dp[10001]{};

int BFS(){
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0;i < N;i++){
            int next = cur + coin[i];
            if(next >= 0 && next <= M && dp[next] == INT_MAX){
                q.push(next);
                dp[next] = dp[cur] + 1;
            }
        }
    }

    if(dp[M] == INT_MAX) return -1;
    return dp[M];
}

int main() {
    cin >> N >> M;
    fill(dp, dp + M + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }
    cout << BFS();

    return 0;
}
