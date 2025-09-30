// 2024 01 23

#include <iostream>
typedef long long int lli;
using namespace std;
lli seg[1 << 21]{};

lli segSum(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 0;
	else if (left <= start && end <= right) return seg[node];
	else {
		int mid = (start + end) / 2;
		return segSum(2 * node, start, mid, left, right) + segSum(2 * node + 1, mid + 1, end, left, right);
	}
}

lli segModify(int node, int start, int end, int index, lli value) {
	if (index < start || index > end) return seg[node];
	else if (start == end) return seg[node] = value;
	else {
		int mid = (start + end) / 2;
		return seg[node] = segModify(2 * node, start, mid, index, value) + segModify(2 * node + 1, mid + 1, end, index, value);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;
		if (i == 0) {
			if (j < k)cout << segSum(1, 1, n, j, k) << '\n';
			else cout << segSum(1, 1, n, k, j) << '\n';
			
		}
		else if (i == 1) {
			segModify(1, 1, n, j, k);
		}
	}

	return 0;
}