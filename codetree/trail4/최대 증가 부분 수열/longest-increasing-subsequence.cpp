#include <iostream>
#include <algorithm>

using namespace std;

int N;
int M[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    int dp[1000]{};
    fill(dp, dp + N, 1);

    for(int i = 0;i < N - 1;i++){
        for(int j = i + 1;j < N;j++){
            if(M[i] < M[j])
                dp[j] = max(dp[i] + 1, dp[j]);
        }
    }

    cout << *max_element(dp, dp + N);

    // Please write your code here.

    return 0;
}
