// 2024 01 28
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> v[100001];
bool check[100001]{false, };
int maxNodeIdx = 0;
int ans = 0;

void search(int start, int sum){
    if(check[start]) return;
    check[start] = true;
    int temp = ans;
    ans = max(sum, ans);
    if(ans > temp) maxNodeIdx = start; 
    
    for(unsigned long int i = 0; i<v[start].size(); i++){
        int y = v[start][i].first;
        if(!check[y]) search(y, sum + v[start][i].second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, parent, child, weight; 
    cin >> n;
    
    for(int i = 0; i<n; i++){
        cin >> parent;
        while(true){
            cin >> child;
            if(child == -1) break;
            cin >> weight;
            v[parent].push_back(make_pair(child, weight));
        }
    }
    search(1, 0);
    memset(check, false, sizeof(check));
    search(maxNodeIdx, 0);
    cout << ans << '\n';
}