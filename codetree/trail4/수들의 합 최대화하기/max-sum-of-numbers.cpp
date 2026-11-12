#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int n;
int grid[10][10];
int max_num = 0;

void backtracking(int depth){
    static int total = 0;
    static vector<bool> visited(n, false);

    if(depth == n){
        max_num = max(total, max_num);
        return;
    }
    for(int i = 0;i < n;i++){
        if(visited[i]) continue;
        total += grid[i][depth];
        visited[i] = true;
        backtracking(depth + 1);
        total -= grid[i][depth];
        visited[i] = false;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    backtracking(0);

    cout << max_num;

    return 0;
}
