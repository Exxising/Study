// 2023 10 25

#include <iostream>
using namespace std;
typedef unsigned long long int ulli;

struct Matrix {
	ulli data[2][2];

	Matrix() {
		data[0][0] = 0;
		data[0][1] = 1;
		data[1][0] = 1;
		data[1][1] = 1;
	}
};

Matrix multi(Matrix& A, Matrix& B) {
	Matrix ret;

	ret.data[0][0] = ((A.data[0][0] * B.data[0][0]) + (A.data[0][1] * B.data[1][0])) % 1000000007;
	ret.data[0][1] = ((A.data[0][0] * B.data[1][0]) + (A.data[0][1] * B.data[1][1])) % 1000000007;
	ret.data[1][0] = ((A.data[1][0] * B.data[0][0]) + (A.data[1][1] * B.data[1][0])) % 1000000007;
	ret.data[1][1] = ((A.data[1][0] * B.data[1][0]) + (A.data[1][1] * B.data[1][1])) % 1000000007;

	return ret;
}

Matrix power(Matrix& A, ulli n) {
	if (n > 1) {
		A = power(A, n / 2);
		A = multi(A, A);

		if (n % 2 == 1) {
			Matrix* temp = new Matrix();
			A = multi(A, *temp);
		}
	}
	return A;
}

ulli fibonacci(ulli n) {
	if (n == 0) return 0;

	Matrix mat;
	mat = power(mat, n);
	
	return mat.data[0][1];
}

int main() {
	ulli n;
	cin >> n;

	cout << fibonacci(n) << '\n';
}