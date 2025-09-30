// 2024 01 09

#include <iostream>
#include <stack>
typedef long long int li;
using namespace std;
int arr[1000001];
int result[1000001];
int F[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		F[arr[i]]++;
	}

	stack<int> st;
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && F[arr[i]] >= F[st.top()]) {
			st.pop();
		}

		if (st.empty()) result[i] = -1;
		else result[i] = st.top();

		st.push(arr[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
	cout << '\n';
	return 0;
}