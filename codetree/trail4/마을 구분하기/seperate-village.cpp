#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[25][25];
int total_person;
vector<vector<bool>> visited;

bool InRange(int r, int c){return r >= 0 && c >= 0 && r < n && c < n;}
bool CanGo(int r, int c){return !visited[r][c] && grid[r][c];}

void DFS(int r, int c){
    static int dr[4] = {0, 0, 1, -1};
    static int dc[4] = {1, -1, 0, 0};
    for(int i = 0;i < 4;i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(InRange(nr, nc) && CanGo(nr, nc)){
            visited[nr][nc] = true;
            total_person++;
            DFS(nr, nc);
        }
    }

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    visited.resize(n, vector<bool>(n, false));
    vector<int> v;
    int cnt_town = 0;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(CanGo(i, j)){
                visited[i][j] = true;
                total_person = 1;
                DFS(i, j);
                v.push_back(total_person);
                cnt_town++;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << cnt_town << "\n";
    for(int i : v) cout << i << "\n";

    return 0;
}
