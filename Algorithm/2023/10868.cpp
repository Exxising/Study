// 2023 05 22

#include <iostream>
#include <math.h>
#define MAX_VALUE 1000000001
using namespace std;
int arr[100001];
int* ans;

int init(int idx, int start, int end) {
	if (start == end) return ans[idx] = arr[start];
	int mid = (start + end) / 2;
	return ans[idx] = min(init(2 * idx + 1, start, mid), init(2 * idx + 2, mid + 1, end));
}

int query(int idx, int start, int end, int left, int right) {
	if (end < left || right < start)					return MAX_VALUE;
	if (left <= start && end <= right)				return ans[idx];

	int mid = (start + end) / 2;
	return min(query(2 * idx + 1, start, mid, left, right), query(2 * idx + 2, mid + 1, end, left, right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	int height = (int)ceil(log2(n));
	int arrSize = 1 << (height + 1);
	ans = new int[arrSize];

	for (int i = 0; i < n; i++) cin >> arr[i];
	init(0, 0, n - 1);

	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << query(0, 0, n - 1, a-1, b-1) << '\n';
	}
}