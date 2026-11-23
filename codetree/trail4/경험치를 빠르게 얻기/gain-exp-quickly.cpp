#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int e[100], t[100];
int dp[1000001]{};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> e[i] >> t[i];
    }

    fill(dp + 1, dp + m + 1, INT_MAX);

    for(int i = 0 ;i < n;i++){
        int temp[1000001];
        copy(dp, dp + m + 1, temp);
        for(int j = 0;j < m;j++){
            if(dp[j] == INT_MAX) continue;
            int next = j + e[i];
            if(next > m) next = m;
            temp[next] = min(temp[next], dp[j] + t[i]);
        }
        copy(temp, temp + m + 1, dp);
    }

    cout << (dp[m] == INT_MAX ? -1 : dp[m]);

    return 0;
}
