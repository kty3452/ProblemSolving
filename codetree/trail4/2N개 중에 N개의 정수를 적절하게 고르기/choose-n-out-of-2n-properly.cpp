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

void backtracking(int start, int depth, int one_set){
    if(depth == n){
        min_num = min(min_num, abs(total - (2 * one_set)));
        return;
    }
    for(int i = start;i < 2 * n;i++){
        backtracking(i + 1, depth + 1, one_set + num[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        total += num[i];
    }

    backtracking(0, 0, 0);

    cout << min_num;

    return 0;
}
