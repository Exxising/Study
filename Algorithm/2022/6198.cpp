// 2022 9 2

#include <iostream>
#include <vector>
using namespace std;
vector <int> v;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int amount, height;
	long long int result = 0;

	cin >> amount;

	for (int i = 0; i < amount; i++) {
		cin >> height;

		while (!v.empty()) {
			if (height >= v.back()) {
				v.pop_back();
			}
			else if (height < v.back()) break;
		}
		result += v.size();

		v.push_back(height);
	}

	cout << result << '\n';
	
	return 0;
}