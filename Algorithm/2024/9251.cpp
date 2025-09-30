// 2024 1 8

#include <iostream>
#include <string>
using namespace std;
int lcs[1001][1001];

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	int len1 = s1.length();
	int len2 = s2.length();

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
			}
		}
	}
	cout << lcs[len1][len2];
}