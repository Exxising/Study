// 2024 01 22
#include <iostream>
typedef long long int lli;
using namespace std;
lli arr[100001];
lli seg[2 << 18];

lli segInit(int node, int start, int end) {
	if (start == end) return seg[node] = arr[start];
	int mid = (start + end) / 2;
	return seg[node] = segInit(2 * node, start, mid) + segInit(2 * node + 1, mid + 1, end);
}

lli segUpdate(lli node, lli start, lli end, lli index, lli value) {
	if (index < start || index > end) return seg[node];
	else if (start == end) return seg[node] = value;
	else {
		int mid = (start + end) / 2;
		return seg[node] = segUpdate(2 * node, start, mid, index, value) + segUpdate(2 * node + 1, mid + 1, end, index, value);
	}
}

lli segQuery(lli node, lli start, lli end, lli left, lli right) {
	if (right < start || left > end) return 0;
	else if (left <= start && end <= right) return seg[node];
	else {
		int mid = (start + end) / 2;
		return segQuery(2 * node, start, mid, left, right) + segQuery(2 * node + 1, mid + 1, end, left, right);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> arr[i];

	segInit(1, 1, n);

	while (q--) {
		lli x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) {
			cout << segQuery(1, 1, n, y, x) << '\n';
		} else {
			cout << segQuery(1, 1, n, x, y) << '\n';
		}
		segUpdate(1, 1, n, a, b);
	}

	return 0;
}