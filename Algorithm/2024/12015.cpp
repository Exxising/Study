// 2024 01 30

#include <iostream>
#include <vector>
using namespace std;
int arr[1000001], lis[1000001];

int search(int start, int end, int value) {
	int mid;
	while (start < end) {
		mid = (start + end) >> 1;
		if (lis[mid] < value) start = mid + 1;
		else end = mid;
	}
	return end;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	lis[0] = arr[0];

	int j = 0;
	for (int i = 1; i <= n; i++) {
		if (lis[j] < arr[i]) {
			lis[j + 1] = arr[i];
			j++;
		}
		else {
			int idx = search(0, j, arr[i]);
			lis[idx] = arr[i];
		}
	}
	cout << j + 1 << '\n';
	return 0;
}