#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

int n;
int num[20];
int min_num = INT_MAX;
int total = 0;

void backtracking(int start, int depth, int one_set, vector<bool>& used){
    if(depth == n){
        min_num = min(min_num, abs(total - (2 * one_set)));
        return;
    }
    for(int i = start;i < 2 * n;i++){
        if(used[i] == false){
            used[i] = true;
            backtracking(i + 1, depth + 1, one_set + num[i], used);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        total += num[i];
    }

    vector<bool> used(2 * n, false);

    backtracking(0, 0, 0, used);

    cout << min_num;

    return 0;
}
