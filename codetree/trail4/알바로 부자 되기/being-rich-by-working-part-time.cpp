#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N;
vector<tuple<int, int, int>> alba;

int main() {
    cin >> N;
    vector<tuple<int, int, int>> alba(N, tuple<int, int, int>(0, 0, 0));
    int dp[1000]{};
    
    for (int i = 0; i < N; i++) {
        int s, e, p;
        cin >> s >> e >> p;
        alba[i] = tie(s, e, p);
        dp[i] = p;
    }

    sort(alba.begin(), alba.end());



    for(int i = 1;i < N;i++){
        for(int j = 0;j < i;j++){
            int s, e, p;
            tie(ignore, e, ignore) = alba[j];
            tie(s, ignore, p) = alba[i];
            if(e >= s) continue;
            dp[i] = max(dp[i], dp[j] + p);
        }
    }

    cout << *max_element(dp, dp + N);


    return 0;
}
