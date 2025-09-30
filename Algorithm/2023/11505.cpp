// 2023 05 22

#include <iostream>
#include <math.h>
#define DIV 1000000007
typedef long long ll;
using namespace std;
ll arr[1000001];
ll* seg;

ll init(int idx, int start, int end) {
	if (start == end) return seg[idx] = arr[start];
	int mid = (start + end) / 2;
	return seg[idx] = (init(2 * idx + 1, start, mid) * init(2 * idx + 2, mid + 1, end)) % DIV;
}

ll mul(int idx, int start, int end, int left, int right) {
	if (end < left || right < start)					return 1;
	if (left <= start && end <= right)				return seg[idx];

	int mid = (start + end) / 2;
	return (mul(2 * idx + 1, start, mid, left, right) * mul(2 * idx + 2, mid + 1, end, left, right)) % DIV;
}

ll update(int idx, int start, int end, int changeIdx, ll val) {
	if (changeIdx > end || changeIdx < start) return seg[idx];
	if (start == end) return seg[idx] = val;

	int mid = (start + end) / 2;
	return seg[idx] = (update(2 * idx + 1, start, mid, changeIdx, val) * update(2 * idx + 2, mid + 1, end, changeIdx, val)) % DIV;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int cnt = m + k;
	int height = (int)ceil(log2(n));
	int arrSize = 1 << (height + 1);
	seg = new ll[arrSize];
	init(0, 0, n - 1);

	while (cnt--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			int c;
			cin >> c;
			arr[b - 1] = c;
			update(0, 0, n-1, b-1, c);
		}
		else if (a == 2) {
			int c;
			cin >> c;
			int maxVal = (b > c) ? b : c;
			int minVal = (b > c) ? c : b;
			cout << mul(0, 0, n - 1, minVal-1, maxVal-1) << '\n';
		}
	}

}