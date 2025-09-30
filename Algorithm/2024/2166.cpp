// 2024 01 31

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<pair<long long int, long long int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	double ans = 0;

	int n;
	long long int t1, t2;
	cin >> n;
	while (n--) {
		long long int x, y;
		cin >> x >> y;
		if (v.empty()) {
			t1 = x;
			t2 = y;
		}
		v.push_back({ x, y });
	}
	v.push_back({ t1, t2 });

	long long int plus = 0, minus = 0;
	for(int i = 0; i<v.size()-1; i++){
		plus += v[i].first * v[i + 1].second;
		minus += v[i].second * v[i + 1].first;
	}

	ans = 0.5 * abs(plus - minus);
	
	cout.precision(1);
	cout << fixed;
	cout << ans << '\n';
}