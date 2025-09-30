// 2024 9 20

#include <iostream>
#include <string.h>
using namespace std;
int ans[10001];

int main() {
	for (int i = 0; i < 10001; i++) {
		ans[i] = 1;
	}

	for (int i = 2; i < 10001; i++) {
		ans[i] += ans[i - 2];
	}

	for (int i = 3; i < 10001; i++) {
		ans[i] += ans[i - 3];
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << ans[n] << '\n';
	}

}