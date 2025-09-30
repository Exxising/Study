// 2024 08 30
#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;

vector<pair<int, int>> vec[20001];
priority_queue<pair<int, int>> pq;
int v, e, s; 

vector<int> dijkstra(int start){
    vector<int> d(v+1, INF);
    // 시작지점의 가중치는 0
    d[start] = 0;
    pq.push({0 , start});
    
    while(!pq.empty()){
        // 가장 첫 번째의 값 받아옴
        int  current = pq.top().second,
            dist = -pq.top().first;
        pq.pop();

        // 저장된 최소 거리보다 dist가 클 경우 다음으로 이동
        if(d[current] < dist) continue;

        for(int i = 0; i<vec[current].size(); ++i){
            int y = vec[current][i].second;
            int nextDist = dist + vec[current][i].first;

            if(nextDist < d[y]){
                d[y] = nextDist;
                pq.push({-nextDist, y});
            }
        }
    }
    return d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> v >> e;
    cin >> s;

    for(int i = 0; i<e; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        vec[from].push_back({weight, to});
    }

    vector<int> ans = dijkstra(s);

    for(int i = 1; i<=v; i++){
        if(ans[i] == INF) cout << "INF" << '\n';
        else cout << ans[i] << '\n';
    }

    return 0;
}