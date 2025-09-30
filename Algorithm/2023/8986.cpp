// 2023 10 27

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long lli;

lli arr[100001];
int n;

inline lli func(lli  x0) {
	lli result = 0;
	for (int i = 1; i < n; ++i) 
		result += abs(1LL * i * x0 - arr[i]);

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	lli l = 0, h = arr[n - 1];

	while (h - l >= 3) {
		lli a = (l * 2 + h) / 3;
		lli b = (l + h * 2) / 3;
		
		if (func(a) <= func(b)) h = b;
		else l = a;
	}

	lli ans = 1e18;
	for (int i = l; i <= h; ++i) {
		ans = min(ans, func(i));
	}

	cout << ans << '\n';
}