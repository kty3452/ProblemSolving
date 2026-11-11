#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
int A[20];
int max_num = 0;

void backtracking(int start, int depth, vector<int>& v){
    if(depth == m){
        vector<int> v_copy = v;
        while(v_copy.size() > 1){
            int last_idx = v_copy.size() - 1;
            int xor_num = v_copy[last_idx] ^ v_copy[last_idx - 1];
            v_copy.pop_back();
            v_copy.pop_back();
            v_copy.push_back(xor_num);
        }
        max_num = max(v_copy[0], max_num);
        return;
    }
    for(int i = start;i < n;i++){
        v.push_back(A[i]);
        backtracking(i + 1, depth + 1, v);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<int> v;
    backtracking(0, 0, v);
    // Please write your code here.

    cout << max_num;

    return 0;
}