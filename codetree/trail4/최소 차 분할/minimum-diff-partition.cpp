#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int dp[100001]{}; // 인덱스는 그룹 A의 합. 값은 그룹 A의 합일 때 B의 합.
    int sum = 0;
    for(int i : arr) sum += i;
    fill(dp, dp + sum + 1, INT_MIN);
    dp[0] = sum;

    for(int i = 0;i < n;i++){
        
        for(int j = sum;j >= 1;j--){
            int idx = j - arr[i];
            if(idx < 0) continue;
            if(dp[idx] == INT_MIN) continue;
            dp[j] = dp[idx] - arr[i];
        }
    }
    int min_num = INT_MAX;
    for(int i = 0;i <= sum;i++){
        min_num = min(abs(i - dp[i]), min_num);
    }
    cout << min_num;

    return 0;
}
