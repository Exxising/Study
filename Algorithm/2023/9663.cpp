// 2023 06 05

#include <iostream>
#include <vector>
using namespace std;
int chess[15];
int n, ans = 0;

int promising(int idx) {
	for (int i = 0; i < idx; i++) {
		if (chess[idx] == chess[i] || idx - i == abs(chess[idx] - chess[i])) {
			return 0;
		}
	}
	return 1;
}

void solution(int idx) {
	if (idx == n) {
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		chess[idx] = i;
		if (promising(idx)) {
			solution(idx + 1);
		}
	}
}

int main() {
	cin >> n;
	solution(0);
	cout << ans << '\n';
	return 0;
}