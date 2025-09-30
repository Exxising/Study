// 2024 09 02
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
#define MAX 1e16
typedef long long ll;
vector<pair<ll, ll>> node[1001];
ll maxValue = 0;
int n, x, m;

ll dijkstra(int start, int end){
    if(start == end) return 0;
    
    vector<ll> vec(n+1, MAX);
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, start});

    while(!pq.empty())
    {
        int current = pq.top().second,
            cost = -pq.top().first;

        pq.pop();

        // 비교할 필요 x
        if(vec[current] < cost) continue;

        for(auto i = 0; i<node[current].size(); i++){
            int next = node[current][i].second,
                nextCost = cost + node[current][i].first;

            if(vec[next] > nextCost){
                vec[next] = nextCost;
                pq.push({-nextCost, next});
            }
        }
    }
    return vec[end];
}

int main(){
    //n명이 x번 마을에 모임, m개의 단방향 도로, Ti 시간 소비
    cin >> n >> m >> x;
    // 간선 정보 등록
    for(int i = 0; i<m; i++){
        int start, dest, cost;
        cin >> start >> dest >> cost;
        node[start].push_back({cost, dest}); // Pair 비교시 첫 번째 인자부터 비교하는 것이 훨씬 동작이 빠름
    }


    for(int i = 1; i<=n; i++){
        ll val = dijkstra(i, x) + dijkstra(x, i);
        if(val > maxValue) maxValue = val;
    }
    cout << maxValue << '\n';
}