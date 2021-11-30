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
	if (row1 < 0 || row2 < 0 || row1 > n || row2 > n) {
		cout << "Error" << endl;
		return;
	}
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

void ColSum(int** matr, int m, int n, int*& sums) {
	
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
	int n, m;
	cin >> m >> n;
	int** matr = new int*[m];
	CreateMatrix(matr, m, n);
	FillMatrix(matr, m, n);
	ShowMatrix(matr, m, n);
	
	//Первое задание
	cout << endl;
	cout << "Enter row to swap: ";
	int i, j;
	cin >> i >> j;
	SwapRow(matr, n, i - 1, j - 1);
	ShowMatrix(matr, m, n);
	
	//Второе задание
	cout << endl <<"Enter value to find: ";
	int x;
	cin >> x;
	cout << "Occurs " << countElement(matr, m, n, x) << " times." << endl;

	//Третье задание
	int* sums = new int[n];
	ColSum(matr, m, n, sums);
	ShowMatrix(matr, m, n);
	for (int i = 0; i < n; i += 1) {
		cout << ((i < n - 1) ? "__" : "_");
	}
	cout << endl;
	for (int i = 0; i < n; i += 1) {
		cout << sums[i] << " ";
	}
	deleteMatrix(matr, m);
	delete[] sums;
}
