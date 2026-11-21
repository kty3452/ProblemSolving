#include <iostream>
#include <climits>

using namespace std;

int n;
int sequence[1000];
int increased[1000];
int decreased[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    const int first_idx = 0;
    const int last_idx = n - 1;
    fill(increased, increased + n, 1);
    fill(decreased, decreased + n, 1);

    for(int now = first_idx;now <= last_idx - 1;now++){
        for(int next = now + 1;next <= last_idx;next++){
            if(sequence[now] < sequence[next]) increased[next] = max(increased[next], increased[now] + 1);
            if(sequence[last_idx - now] < sequence[last_idx - next]) decreased[last_idx - next] = max(decreased[last_idx - next], decreased[last_idx - now] + 1);
        }
    }

    int max_num = INT_MIN;

    for(int i = first_idx;i <= last_idx;i++){
        max_num = max(max_num, increased[i] + decreased[i] - 1);
    }
    cout << max_num;


    return 0;
}
