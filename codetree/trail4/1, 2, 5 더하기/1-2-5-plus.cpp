#include <iostream>
#include <algorithm>

using namespace std;
#define MOD 10007

int n;

int main() {
    cin >> n;
    int nums[3] = {1, 2, 5};
    int dp[1001]{};
    dp[0] = 1;

    for(int i = 1;i <= n;i++){
        for(int num : nums){
            int before = i - num;
            if(before < 0) continue;
            dp[i] = (dp[i] + dp[before]) % MOD;
        }
    }

    cout << dp[n];


    return 0;
}
