
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int arr[100];
int dp[100001]{}; // idx는 A와 B의 차이. 값은 가능한 A의 최대값.

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    fill(dp + 1, dp + sum + 1, INT_MIN);

    for(int j = 0;j < n;j++){
        int temp[100001];
        copy(dp, dp + sum + 1, temp);
        for(int cur = 0;cur < sum;cur++){
            if(dp[cur] == INT_MIN) continue;
            int next = cur + arr[j];
            if(next > sum) break;
            temp[next] = max(temp[next], dp[cur] + arr[j]);
            int gap = abs(cur - arr[j]); // B에 원소를 추가했을 때 생기는 갭차이, B가 더 커질 가능성이 존재하기 때문에(인덱스가 음수가 될 수 있기에) 절댓값으로 환산
            int A = max(dp[cur], dp[cur] - cur + arr[j]); // B가 더 커졌다면 A의 합과 B의 합을 뒤바꿔줌.
            temp[gap] = max(temp[gap], A); //새로운 원소를 B에 추가했을 떄의 갭 차이(gap)에서의 기존 값과 새롭게 만들어진 A 중 더 큰 값을 넣음.
        }
        copy(temp, temp + sum + 1, dp);
    }

    cout << dp[0];

    

    return 0;
}
