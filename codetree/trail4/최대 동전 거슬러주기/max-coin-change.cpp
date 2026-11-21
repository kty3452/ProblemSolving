#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
int coin[100];
int dp[10001];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }
    sort(coin, coin + N);
    fill(dp, dp + M + 1, -1);
    dp[0] = 0;

    for(int i = 1;i <= M;i++){
        for(int j = 0;j < N;j++){
            int before = i - coin[j];
            if(before < 0) break;
            if(dp[before] == -1) continue;
            dp[i] = max(dp[i], dp[before] + 1);
        }
    }
    cout << dp[M];

    return 0;
}
