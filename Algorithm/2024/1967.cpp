// 2024 01 28

#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> v[10001];
bool check[10001]{false, };
int ans = 0;

void search(int start, int sum){
    if(check[start]) return;
    check[start] = true;
    ans = max(sum, ans);
    
    for(unsigned long int i = 0; i<v[start].size(); i++){
        int y = v[start][i].first;
        if (!check[y]) search(y, sum + v[start][i].second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i<n-1; i++){
        int parent, child, weight;
        cin >> parent >> child >> weight;
        v[parent].push_back(make_pair(child, weight));
        v[child].push_back(make_pair(parent, weight));
    }
    
    for(int i = 1; i<=n; i++){
        memset(check, false, sizeof(check));
        search(i, 0);
    }

    cout << ans << '\n';
}