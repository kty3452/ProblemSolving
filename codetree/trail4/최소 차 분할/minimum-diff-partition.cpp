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
    // int dp[100001]{}; // 인덱스는 그룹 A의 합. 값은 그룹 A의 합일 때 B의 합.
    bool dp[100001]{}; // 인덱스는 그룹 A의 합. 값은 해당 값이 가능한지 여부.
    int sum = 0;
    for(int i : arr) sum += i;
    dp[0] = true;

    for(int i = 0;i < n;i++){
        
        for(int j = sum;j >= 1;j--){
            int idx = j - arr[i];
            if(idx < 0) continue;
            if(!dp[idx]) continue; // i번째 수까지 고려했는데 해당 값이 불가능하면 넘어감.
            dp[j] = true;
        }
    }
    int min_num = INT_MAX;
    for(int i = 0;i <= sum;i++){
        if(dp[i]) min_num = min(abs(i * 2 - sum), min_num);
    }
    cout << min_num;

    return 0;
}
