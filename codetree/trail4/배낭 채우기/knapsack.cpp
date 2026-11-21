#include <iostream>

using namespace std;

int N, M;
int w[100], v[100];

int main() {
    cin >> N >> M;

    int dp[10001]{};

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    for(int i = 0;i < N;i++){
        for(int j = M;j >= 1;j--){
            int idx = j - w[i];
            if(idx < 0) break;
            dp[j] = max(dp[idx] + v[i], dp[j]);
        }
    }

    cout << dp[M];

    

    return 0;
}
