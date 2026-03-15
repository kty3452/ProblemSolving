#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> virus;
vector<pair<int, int>> dv = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, max_num = 0, wall = 3;

void backtracking(vector<vector<int>>& v, int r, int c, int depth){
    if(depth == 3){
        int cnt = wall;
        vector<vector<int>> temp = v;
        for(auto [a, b] : virus){
            queue<pair<int, int>> q;
            q.push({a, b});
            cnt++;
            while(!q.empty()){
                auto [cr, cc] = q.front();
                q.pop();
                for(auto [dr, dc] : dv){
                    auto [nr, nc] = pair{cr + dr, cc + dc};
                    if(!temp[nr][nc]){
                        temp[nr][nc] = 2;
                        q.push({nr, nc});
                        cnt++;
                    }
                }
            }
        }
        max_num = max((n * m) - cnt, max_num);

        return;
    }


    for(int i = r;i <= n;i++){
        for(int j = (i == r ? c : 1);j <= m;j++){ // 행이 바뀔 경우, 1부터 탐색
            if(!v[i][j]){
                v[i][j] = 1;
                backtracking(v, i, j, depth + 1);
                v[i][j] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> v(n + 2, vector<int>(m + 2, 1));
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> v[i][j];
            if(v[i][j] == 2) virus.push_back({i, j});
            else if(v[i][j] == 1) wall++;
        }
    }

    backtracking(v, 1, 1, 0);

    cout << max_num;

    return 0;
}