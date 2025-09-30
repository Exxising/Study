// 2022 09 02
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector <int> v;

int main() {
	int length, del;
	string number;

	cin >> length >> del;
	cin >> number;

	for (int i = 0; i < length; i++) {		
		int curNum = number[i] - '0';
		while (!v.empty() && del != 0) {
			if (curNum > v.back()) {
				v.pop_back();
				del--;
			}
			else break;
		}
		v.push_back(curNum);
	}

	while (del != 0) {
		v.pop_back();
		del--;
	}

	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it;

	return 0;
}