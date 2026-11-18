#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> lines;

int main() {
    cin >> n;
    lines.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i].first >> lines[i].second;
    }
    sort(lines.begin(), lines.begin() + n);
    int dp[1000]{};
    fill(dp, dp + n, 1);
    for(int i = 1;i < n;i++){
        for(int j = 0;j < i;j++){
            int num = dp[j];
            if(lines[i].first > lines[j].second) num++; 
            dp[i] = max(dp[i], num);
        }
    }

    cout << *max_element(dp, dp + n);



    return 0;
}
