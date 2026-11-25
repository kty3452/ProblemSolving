#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int dp[100000];
    dp[0] = arr[0];
    
    for(int i = 1;i < n;i++){
        dp[i] = max(dp[i - 1] + arr[i], arr[i]); 
    }

    cout << *max_element(dp, dp + n);

    return 0;
}
