#include <iostream>
#include <vector>

using namespace std;

int n;

void cal_r_p(int depth){
    static vector<bool> visited(n, false);
    static vector<int> v;
    if(depth == n){
        for(int i : v) cout << i << " ";
        cout << "\n";
    }
    for(int i = n;i >= 1;i--){
        if(visited[i]) continue;

        visited[i] = true;
        v.push_back(i);
        cal_r_p(depth + 1);
        visited[i] = false;
        v.pop_back();
    }
}

int main() {
    cin >> n;

    cal_r_p(0);

    return 0;
}
