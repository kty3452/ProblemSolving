// 15:19 시작
// 아마 그리드 인듯. 시작 꽃만 정해놓고 그 전에 피는 놈중에 제일 늦게 지는 놈을 고르면 됨.
// 16:09까지 고민
// 22:13 풀이 재개
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <deque>
#include <tuple>

using namespace std;

bool can_in(int end1, int end2, int start1, int start2){
    if(start1 < end1 || (start1 == end1 && start2 <= end2)) return true;
    return false;
}

bool bigger(int month, int day, int month2, int day2){
    if(month < month2 || (month == month2 && day < day2)) return true;
    return false;
}

bool compare(vector<int> a, vector<int> b){
    if(tie(a[2], a[3]) == tie(b[2], b[3])){
        return bigger(a[0], a[1], b[0], b[1]);
    }
    return bigger(a[2], a[3], b[2], b[3]);
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> date(n, vector<int>(4, 0));
    for(int i = 0;i < n;i++){
        cin >> date[i][0] >> date[i][1] >> date[i][2] >> date[i][3];
    }
    sort(date.begin(), date.end(), compare);
    
    vector<vector<int>> flower;
    flower.push_back({3, 1, 3, 1});

    for(int i = 0;i < n;i++){
        if(can_in(3, 1, date[i][2], date[i][3])|| !can_in(flower[flower.size() - 1][2], flower[flower.size() - 1][3], date[i][0], date[i][1])) continue;

        for(int j = flower.size() - 1;j >= 1;j--){
            if(can_in(flower[j - 1][2], flower[j - 1][3], date[i][0], date[i][1])){
                flower.pop_back();
            }
            else break;
        }
        flower.push_back(date[i]);
    }
    for(int j = flower.size() - 1;j >= 1;j--){
        if(flower[j - 1][2] > 11 && flower[j - 1][3] > 0){
            flower.pop_back();
        }
        else break;
    }
    if(flower[flower.size() - 1][2] > 11 && flower[flower.size() - 1][3] > 0) cout << flower.size() - 1;
    else cout << 0;
    
    return 0;
}