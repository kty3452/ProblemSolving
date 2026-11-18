#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int arr[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int dp[1000]{};
    fill(dp, dp + n, INT_MIN);
    dp[0] = 0;

    for(int i = 0;i < n;i++){
        while(arr[i]--){
            if(i + arr[i] + 1 < n)
                dp[i + arr[i] + 1] = max(dp[i + arr[i] + 1], dp[i] + 1);
        }
    }

    cout << *max_element(dp, dp + n);

    // Please write your code here.

    return 0;
}
