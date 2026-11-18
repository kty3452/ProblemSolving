#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN_N 0
#define MAX_N 100

int n;
int grid[100][100];
vector<vector<bitset<101>>> v;
int answer = 0;

void Init(int gap){
    // v.assign(n, vector<bitset<101>>(n, bitset<101>(0)));
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         for(int k = max(grid[i][j] - gap, 1);k <= grid[i][j];k++){
    //             v[i][j][k] = 1;
    //         }
    //     }
    // }

    bitset<101> allowed[101];

    for (int value = 1; value <= 100; value++) {
        for (int k = max(1, value - gap); k <= value; k++) {
            allowed[value].set(k);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j] = allowed[grid[i][j]];
        }
    }


    for(int i = 1;i < n;i++){
        v[i][0] = v[i - 1][0] & v[i][0];
        v[0][i] = v[0][i - 1] & v[0][i];
    }

}



bool CalBit(int gap){
    Init(gap);

    for(int i = 1;i < n;i++){
        for(int j = 1;j < n;j++){
            v[i][j] = (v[i - 1][j] | v[i][j - 1]) & v[i][j];
        }
    }
    return v[n - 1][n - 1].any();
}

void ParametricSearch(int left, int right){
    if(left > right) return;
    int mid = (left + right) / 2;
    bool able = CalBit(mid);
    if(able) {
        answer = mid;
        ParametricSearch(left, mid - 1);
    }
    else ParametricSearch(mid + 1, right);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    v.resize(n, vector<bitset<101>>(n, bitset<101>(0)));

    ParametricSearch(MIN_N, MAX_N);

    cout << answer;

    return 0;
}
