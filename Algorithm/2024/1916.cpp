// 2024 01 29

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e12
typedef long long int lli;
using namespace std;
vector<pair<int, int>> v[100001];
lli cost[1001];

void dijkstra(int start) {
	cost[start] = 0;
	
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int current = pq.top().first,
			distance = -pq.top().second;
		pq.pop();

		if (cost[current] < distance) continue;
		for (unsigned long int i = 0; i < v[current].size(); ++i) {
			int next = v[current][i].first;
			int nextDistance = distance + v[current][i].second;
			
			if (nextDistance < cost[next]) {
				cost[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main() {
	int n, m, start, end;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cost[i] = INF;

	for (int i = 0; i < m; i++) {
		int s, d, c;
		cin >> s >> d >> c;
		v[s].push_back(make_pair(d, c));
	}
	cin >> start >> end;
	dijkstra(start);
	cout << cost[end] << '\n';
}