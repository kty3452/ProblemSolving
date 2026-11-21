// 보석 개수가 무제한이라면 굳이 하나씩 따질 필요 없이 매번 모든 것들을 갱신하면 되겠네?

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int w[100], v[100];
int dp[10001]{};

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    for(int i = 1;i <= M;i++){ // 각 무게마다 가능한 최대 가치를 고를건데
        for(int j = 0;j < N;j++){ // 보석 하나씩 다 대조해볼꺼야~
            if(w[j] > i) continue;
            dp[i] = max(dp[i - w[j]] + v[j], dp[i]);
        }
    }

    cout << dp[M];

    return 0;
}
