#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int grid[10][10];
int max_num = 0;

void backtracking(int r){
    static vector<bool> visited(n, false);
    static vector<int> num(n, 0);
    if(r == n){
        max_num = max(max_num, *min_element(num.begin(), num.end()));
        return;
    }
    for(int c = 0;c < n;c++){
        if(visited[c]) continue;
        
        visited[c] = true;
        num[r] = grid[r][c];        
        backtracking(r + 1);
        visited[c] = false;
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
