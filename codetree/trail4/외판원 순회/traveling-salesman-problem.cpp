#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int A[10][10];
int min_num = INT_MAX;

void backtracking(int depth, int cur_address){
    static vector<bool> visited(n, false);
    static int total = 0;
    if(depth == n - 1){
        if(A[cur_address][0] == 0) return;
        min_num = min(min_num, total + A[cur_address][0]);
        return;
    }
    for(int next_address = 1;next_address < n;next_address++){
        if(visited[next_address] || A[cur_address][next_address] == 0) continue;
        visited[next_address] = true;
        total += A[cur_address][next_address];
        backtracking(depth + 1, next_address);
        visited[next_address] = false;
        total -= A[cur_address][next_address];
    }

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    backtracking(0, 0);

    cout << min_num;

    return 0;
}
