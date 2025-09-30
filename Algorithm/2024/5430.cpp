// 2024 1 18

#include <iostream>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char separator = ',';

	int t;
	cin >> t;
	while (t--) {
		deque<char> command;
		deque<int> number;
		istringstream iss();

		string cmd, arr, buffer;
		int cnt;


		// 0 = front, 1 = back;
		bool _front = 0, isError = false;

		cin >> cmd >> cnt >> arr;

		for (int i = 0; i < cmd.length(); ++i) {
			command.push_back(cmd[i]);
		}

		// 숫자 문자열 앞 뒤 괄호 제거
		arr.erase(arr.begin());
		arr.erase(arr.end() - 1);
		stringstream ss(arr);
		
		// 숫자 덱에 집어넣기
		while (getline(ss, buffer, separator)) {
			number.push_back(stoi(buffer));
		}

		// 명령어 처리
		while (!command.empty()) {
			if (command.front() == 'R') {
				if (_front == 0) _front = 1;
				else _front = 0;
			}
			else if (command.front() == 'D') {
				// 숫자 덱이 비어있을 때 D를 호출하면 에러 발생
				if (number.empty()) {
					isError = true;
					break;
				}

				if (_front == 0) {
					number.pop_front();
				}
				else {
					number.pop_back();
				}
			}
			command.pop_front();
		}

		// 에러가 발생한 경우와 아닌 경우 출력
		if (isError) {
			cout << "error" << '\n';
		}
		else {
			cout << "[";
			while (!number.empty()) {
				if (_front == 0) {
					cout << number.front();
					number.pop_front();
				}
				else {
					cout << number.back();
					number.pop_back();
				}
				if (number.size() >= 1) cout << ",";
			}
			cout << "]" << '\n';
		}
	}

	return 0;
}