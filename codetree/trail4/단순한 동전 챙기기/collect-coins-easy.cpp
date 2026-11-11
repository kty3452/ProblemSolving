#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int N;
char grid[20][20];
pair<int, int> start_idx;
pair<int, int> end_idx;
vector<vector<pair<int, int>>> num;
int min_num = INT_MAX;

int uclid(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second); 
}

void backtracking(int start, vector<pair<int, int>>& v){
    if(v.size() == 4){
        v.push_back(end_idx);
        int total = 0;
        for(int i = 1;i < v.size();i++){
            total += uclid(v[i], v[i - 1]);
        }
        min_num = min(total, min_num);
        v.pop_back();
        return;
    }

    for(int i = start;i < num.size();i++){
        for(int j = 0;j < num[i].size();j++){
            v.push_back(num[i][j]);
            backtracking(i + 1, v);
            v.pop_back();
        }
    }

}

int main() {
    cin >> N;
    num.resize(10, vector<pair<int, int>>());

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'S') start_idx = pair{i, j}; 
            else if(grid[i][j] == 'E') end_idx = pair{i, j}; 
            else if(grid[i][j] != '.') num[grid[i][j] - '0'].push_back({i, j});
        }
    

    vector<pair<int, int>> v;
    v.push_back(start_idx);

    backtracking(1, v);
    if(min_num == INT_MAX) min_num = -1;
    cout << min_num;
    // Please write your code here.

    return 0;
}
