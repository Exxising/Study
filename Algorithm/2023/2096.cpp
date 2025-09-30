// 2023 03 12

#include <iostream>
#include <cstring>
using namespace std;
int maxDp[3]{ 0,0,0 }, minDp[3]{ 0,0,0 };
int input[3];

int main() {
	int n;
	cin >> n;
	cin >> maxDp[0] >> maxDp[1] >> maxDp[2];
	minDp[0] = maxDp[0];
	minDp[1] = maxDp[1];
	minDp[2] = maxDp[2];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++)
			cin >> input[j];

		int t0 = maxDp[0], t1 = maxDp[1], t2 = maxDp[2];
		maxDp[0] = input[0] + max(t0, t1);
		maxDp[1] = input[1] + max(t2, max(t0, t1));
		maxDp[2] = input[2] + max(t1, t2);
		
		int mt0 = minDp[0], mt1 = minDp[1], mt2 = minDp[2];
		minDp[0] = input[0] + min(mt0, mt1);
		minDp[1] = input[1] + min(mt0, min(mt1, mt2));
		minDp[2] = input[2] + min(mt1, mt2);
	}
	cout << max(maxDp[2], max(maxDp[0], maxDp[1])) << " " << min(minDp[2], min(minDp[0], minDp[1]));

	return 0;
}