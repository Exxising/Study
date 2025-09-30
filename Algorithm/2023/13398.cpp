// 2023 10 27

#include <iostream>
using namespace std;
int dp[100001][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, ans;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		dp[i][0] = dp[i][1] = m;
		if (i == 0) {
			ans = m;  continue;
		}
		dp[i][0] = max(dp[i - 1][0] + m, m);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + m);
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}

	cout << ans << '\n';
}