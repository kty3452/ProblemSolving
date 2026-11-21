#include <iostream>

using namespace std;

int n, m;
int A[100];
bool dp[10001]{};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    dp[0] = true;

    for(int i = 0;i < n;i++){
        for(int j = m;j >= 1;j--){
            int idx = j - A[i];
            if(idx < 0) break;
            if(dp[idx] == false) continue;
            dp[j] = true;
        }
    }

    if(dp[m]) cout << "Yes";
    else cout << "No";

    return 0;
}
