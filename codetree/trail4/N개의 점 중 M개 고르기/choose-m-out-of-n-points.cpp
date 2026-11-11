#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int n, m;
int x[20], y[20];
vector<vector<double>> uclid;
double min_num = INT_MAX;

double cal_uclid(int x1, int y1, int x2, int y2){
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

void backtracking(int start, int depth, vector<int> coordinate){
    if(depth == m){
        double max_num = 0;
        for(int i = 0;i < m - 1;i++){
            for(int j = i + 1;j < m;j++){
                max_num = max(max_num, uclid[coordinate[i]][coordinate[j]]);
            }
        }
        min_num = min(min_num, max_num);
        return;
    }

    for(int i = start;i < n;i++){
        coordinate.push_back(i);
        backtracking(i + 1, depth + 1, coordinate);
        coordinate.pop_back();
    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    uclid.resize(n, vector<double>(n, 0));

    for(int i = 0;i < n - 1;i++){
        for(int j = i + 1;j < n;j++){
            uclid[i][j] = cal_uclid(x[i], y[i], x[j], y[j]);
        }
    }

    vector<int> coordiante;
    backtracking(0, 0, coordiante);

    cout << (int) min_num;

    return 0;
}
