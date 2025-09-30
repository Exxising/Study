// 2022 9 2
#include <iostream>
#include <vector>
using namespace std;
vector<pair <int, int>> v;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int amount, height;
	cin >> amount;
	for (int i = 0; i < amount; i++) {
		cin >> height;
		while (!v.empty()) {
			if (height < v.back().second) {
				cout << v.back().first << " ";
				break;
			}
			v.pop_back();
		}
		if (v.empty()) {
			cout << "0" << " ";
		}

		v.push_back(make_pair(i+1, height));
	}
}