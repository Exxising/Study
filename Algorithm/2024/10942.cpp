// 2024 01 29

#include <iostream>
#include <string.h>
using namespace std;
int dp[2001][2001];
int arr[2001];
int n, m, s, e;

int solution(int start, int end) {
	if (dp[start][end] != -1) return dp[start][end];
	else if (start == end) return dp[start][end] = 1;
	else if (arr[start] != arr[end]) return dp[start][end] = 0;
	else if (end - start == 1 && arr[start] == arr[end]) return dp[start][end] = 1;
	else return dp[start][end] = solution(start + 1, end - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	cin >> m;
	while (m--) {
		cin >> s >> e;
		if(dp[s][e] == -1) solution(s, e);
		cout << dp[s][e] << '\n';
	}

}