#include <iostream>
using namespace std;

void CreateMatrix(int**& matr, int m, int n){
	for (int i = 0; i < m; i += 1) {
		matr[i] = new int[n];
	}
}

void FillMatrix(int**& matr, int m, int n) {
	for (int i = 0; i < m; i += 1) {
		for (int j = 0; j < n; j += 1) {
			matr[i][j] = i + j;
		}
	}
}

void SwapRow(int**& matr, int n, int row1, int row2) {
	for (int j = 0; j < n; j += 1) {
		int tmp = matr[row1][j];
		matr[row1][j] = matr[row2][j];
		matr[row2][j] = tmp;
	}
}

void ShowMatrix(int** matr, int m, int n) {
	for (int i = 0; i < m; i += 1) {
		for (int j = 0; j < n; j += 1) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}

int countElement(int** matr, int m, int n, int el) {
	int ans = 0;
	for (int i = 0; i < m; i += 1) {
		for (int j = 0; j < n; j += 1) {
			if (matr[i][j] == el) ans += 1;
		}
	}
	return ans;
}

void ColSum(int** matr, int m,int n, int*& sums) {
	
	for (int j = 0; j < n; j += 1) {
		int sum = 0;
		for (int i = 0; i < m; i += 1) {
			sum += matr[i][j];
		}
		sums[j] = sum;
	}
}

void deleteMatrix(int** matr, int m) {
	for (int i = 0; i < m; i += 1) {
		delete[] matr[i];
	}
	delete[] matr;
}

void main() {
	int** matr = new int*[3];
	int n, m;
	cin >> n >> m;
	CreateMatrix(matr, m, n);
	FillMatrix(matr, m, n);
	ShowMatrix(matr, m, n);

	cout << endl;
	SwapRow(matr, n, 0, 1);
	ShowMatrix(matr, m, n);

	cout << endl << countElement(matr, m, n, 1) << endl;

	int* sums = new int[n];
	ColSum(matr, m, n, sums);
	ShowMatrix(matr, m, n);
	cout << endl;
	for (int i = 0; i < n; i += 1) {
		cout << sums[i] << " ";
	}

	deleteMatrix(matr, m);
	delete[] sums;
}