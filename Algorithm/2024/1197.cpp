// 2024 01 30

#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, int>> v[100001];
bool visited[10001];

struct comp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

long long int search(int start) {
	long long int ans = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	pq.push({ start, 0 });
	
	while (!pq.empty()) {
		int current = pq.top().first,
			weight = pq.top().second;
		pq.pop();

		if (visited[current]) continue;
		visited[current] = true;
		ans += weight;
		
		for (unsigned long int i = 0; i < v[current].size(); ++i) {
			if (!visited[v[current][i].first] ) pq.push(v[current][i]);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(visited, false, sizeof(visited));
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		v[v1].push_back({ v2, w });
		v[v2].push_back({ v1, w });
	}

	cout << search(1) << '\n';
	return 0;
}