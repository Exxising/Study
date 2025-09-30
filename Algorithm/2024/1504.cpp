// 2024 09 04
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1e16
using namespace std;
typedef long long ll;
vector<pair<ll, ll>> vec[801];
int n, e, v1, v2;

ll dijkstra(int start, int end){
    vector<ll> d(n+1, MAX);
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, start});
    
    if(start == end) return 0;

    while(!pq.empty()){
        int current = pq.top().second;
        ll  cost = -pq.top().first;

        pq.pop();
        if(d[current] < cost) continue;

        for(auto i = 0; i<vec[current].size(); i++){
            int y = vec[current][i].second;
            ll nextDist = cost + vec[current][i].first;

            if(d[y] > nextDist){
                d[y] = nextDist;
                pq.push({-nextDist, y});
            }
        }
    }
    return d[end];
}

int main(){
    cin >> n >> e;
    // non-direction
    for(int i = 0; i<e; i++){
        int from, to, dist;
        cin >> from >> to >> dist;
        vec[from].push_back({dist, to});
        vec[to].push_back({dist, from});
    }
    cin >> v1 >> v2;

    // compare
    // 1. start to v1 + end to v2 + v1 to v2
    // 2. start to v2 + end to v2 + v1 to v2

    ll first = dijkstra(1, v1) + dijkstra(n, v2);
    ll second = dijkstra(1, v2) + dijkstra(n, v1);
    ll minCostBetweenV1V2 = min(dijkstra(v1, v2), dijkstra(v2, v1));
    
    if(first >= MAX || second >= MAX || minCostBetweenV1V2 >= MAX){
        cout << -1 << '\n';
        return 0;
    }
    cout << min(first, second) + minCostBetweenV1V2 << '\n';
    // 82%
}