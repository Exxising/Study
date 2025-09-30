// 2024 01 31

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, int>> v[1001];
bool visited[1001];

struct comp {
	bool operator() (pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

int search(int start) {
	long long int ans = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int next = pq.top().first,
			weight = pq.top().second;
		pq.pop();

		if (visited[next]) continue;
		visited[next] = true;
		ans += weight;

		for (unsigned long int i = 0; i < v[next].size(); ++i) {
			if (!visited[v[next][i].first]) pq.push(v[next][i]);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m; cin >> n;
	cin >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	cout << search(1) << '\n';
}