#include <iostream>
#include <climits>
#include <algorithm>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int num[100];
int dp[10001][101];

int search(){
    for(int i = 1;i <= M;i++){
        for(int use_last_num_idx = 1;use_last_num_idx <= N;use_last_num_idx++){
            for(int next_idx = use_last_num_idx;next_idx < N;next_idx++){
                if (dp[i][use_last_num_idx] == INT_MAX) continue;
                int next = i + num[next_idx];
                if(next > M) continue;
                dp[next][next_idx + 1] = min(dp[next][next_idx + 1], dp[i][use_last_num_idx] + 1);
            }
        }
    }

    int min_num = *min_element(dp[M], dp[M] + N + 1);
    if(min_num == INT_MAX) return -1;
    else return min_num;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    for(int i = 0;i <= M;i++){
        fill(dp[i], dp[i] + N + 1, INT_MAX);
    }
    dp[0][0] = 0;

    for(int i = 0;i < N;i++){
        int next = num[i];
        if(next > M) continue;
        dp[next][i + 1] = dp[0][0] + 1;
    }
    cout << search();

    return 0;
}
