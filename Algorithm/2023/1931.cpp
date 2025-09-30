// 2023 10 24

#include <iostream>
#include <queue>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		pq.push(make_pair(start, end));
	}

	int prevStart = 0;
	int prevEnd = 0;
	for (int i = 0; i < n; i++) {
		if (prevEnd == 0) {
			prevStart = pq.top().first;
			prevEnd = pq.top().second;
			ans++;
		}
	else if (pq.top().first >= prevStart && pq.top().first <= prevEnd && pq.top().second < prevEnd) {
			prevStart = pq.top().first;
			prevEnd = pq.top().second;
		}
		else if (pq.top().first >= prevEnd) {
			prevStart = pq.top().first;
			prevEnd = pq.top().second;
			ans++;
		}
		pq.pop();
	}
	cout << ans << '\n';

}