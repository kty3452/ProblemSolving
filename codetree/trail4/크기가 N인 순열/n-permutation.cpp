#include <iostream>
#include <vector>

using namespace std;

int n;

void cal_p(int depth, vector<int>& v, vector<bool>& visited){
    if(depth == n){
        for(int i : v) cout << i <<" ";
        cout << "\n";
        return;
    }
    for(int i = 1;i <= n;i++){
        if(visited[i] == false)
            {visited[i] = true;
            v.push_back(i);
            cal_p(depth + 1, v, visited);
            visited[i] = false;
            v.pop_back();}
    }
}

int main() {
    cin >> n;
    vector<int> v; 
    vector<bool> visited(n + 1, false);    
    cal_p(0, v, visited);

    // Please write your code here.

    return 0;
}
