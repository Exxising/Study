// 2024 01 30

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1000001], lis[1000001], ans[1000001];
int j;

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

	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	lis[0] = arr[0]; j = 0;

	for (int i = 1; i < n; i++) {
		if (lis[j] < arr[i]) {
			lis[j + 1] = arr[i];
			ans[i] = j + 1;
			j++;
		}
		else {
			int idx = search(0, j, arr[i]);
			lis[idx] = arr[i];
			ans[i] = idx;
		}
	}
	cout << j + 1<< '\n';
	int length = j;
	for (int i = n-1; i >= 0; i--) {
		if (j == ans[i]) {
			v.push_back(arr[i]);
			j--;
		}
	}

	sort(v.begin(), v.end());
	for (auto i : v) cout << i << " ";

	return 0;
}