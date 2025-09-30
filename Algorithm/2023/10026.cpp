// 2023 3 27

#include <iostream>
#include <string.h>
using namespace std;
char arr[101][101];
bool check[101][101];
int nor, abn, n;

int posX[4] = { 1, 0, -1, 0 };
int posY[4] = { 0, -1, 0, 1 };

void abnormal(int x, int y) {
	if (check[x][y]) return;

	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int newPosX = x + posX[i];
		int newPosY = y + posY[i];

		if (arr[x][y] == 'R' || arr[x][y] == 'G') {
			if (arr[newPosX][newPosY] == 'R' || arr[newPosX][newPosY] == 'G' && !check[newPosX][newPosY]){
				abnormal(newPosX, newPosY);
			}
		} else if (arr[x][y] == arr[newPosX][newPosY] && !check[newPosX][newPosY]) {
			abnormal(newPosX, newPosY);
		}
	}
}

void normal(int x, int y) {
	if (check[x][y]) return;

	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int newPosX = x + posX[i];
		int newPosY = y + posY[i];

		if (arr[x][y] == arr[newPosX][newPosY] && !check[newPosX][newPosY]) {
			normal(newPosX, newPosY);
		}
	}
}

int main() {
	nor = abn = 0;

	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				nor++;
				normal(i, j);
			}
		}
	}
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				abn++;
				abnormal(i, j);
			}
		}
	}

	cout << nor << " " << abn << '\n';
	return 0;
}
