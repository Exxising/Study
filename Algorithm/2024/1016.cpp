// 2024 01 04

#include <iostream>
#include <cmath>
typedef unsigned long long int ulli;
using namespace std;
bool check[1000001];

int main() {
	ulli min, max, j, result = 0;
	cin >> min >> max;

	for (ulli i = 2; i <= sqrt(max); i++) {
		j = ceil((double)min / (i * i)) * (i * i);
		for (; j <= max; j += i * i) {
			check[j - min] = true;
		}
	}

	for (ulli i = 0; i <= max - min; i++) {
		if (!check[i]) result++;
	}

	cout << result << '\n';

}