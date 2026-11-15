#include <iostream>
#include <queue>

using namespace std;

int N;
int visited[2000001]{};
queue<int> q;

bool InRange(int n){
    return n >= 0 && n < N * 2;
}

void Push(int n, int next_n){
    q.push(next_n);
    visited[next_n] = visited[n] + 1;
}

void BFS(){
    while(!q.empty()){
        int n = q.front();
        q.pop();
        
        if(InRange(n + 1) && !visited[n + 1]){
            Push(n, n + 1);
        }
        if(InRange(n - 1) && !visited[n - 1]){
            Push(n, n - 1);
        }
        if(n % 2 == 0 && InRange(n / 2) && !visited[n / 2]){
            Push(n, n / 2);
        }
        if(n % 3 == 0 && InRange(n / 3) && !visited[n / 3]){
            Push(n, n / 3);
        }
    }
}

int main() {
    cin >> N;
    
    visited[N] = 1;
    q.push(N);

    BFS();

    cout << visited[1] - 1;

    return 0;
}
