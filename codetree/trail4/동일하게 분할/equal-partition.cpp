#include <iostream>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;
    int sum = 0;
    bool dp[100001]{};
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum % 2 == 1) cout << "No";
    else{
        for(int i = 0;i < n;i++){
            for(int j = sum;j > 0;j--){
                int idx = j - arr[i];
                if(idx < 0) break;
                if(dp[idx] == false) continue;
                dp[j] = true;
            }
        }
        cout << (dp[sum/2] == true ? "Yes" : "No");
    }
    
    

    // Please write your code here.

    return 0;
}
