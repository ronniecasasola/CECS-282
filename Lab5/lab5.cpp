//Ronnie Casasola 012737398
//CECS 282 Lab 5
#include<iostream>
using namespace std;

float *allocate(int rows, int cols) {
	float* mat = new float[rows*cols];
	return mat;
}

void readm(float *matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i*cols + j];
		}
	}
}

void writem(float *matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i*cols + j] << " ";
		}
		cout << endl;
	}
}

float calculate(float *matrix1, int st1, int en1, float *matrix2, int st2, int cols2) {
	float total = 0.0;
	for (int i = st1; i < en1; i++) {
		total += matrix1[i] * matrix2[st2];
		st2 += cols2;
	}
	return total;
}

void mulmatrix(float *matrix1, int rows1, int cols1, float *matrix2, int cols2, float *product) {
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols2; j++)
			product[i*cols2 + j] = calculate(matrix1, i*cols1, i*cols1 + cols1, matrix2, j, cols2);
	}
	writem(product, rows1, cols2);
}

int main() {
	int row_1, col_1;
	cout << "Enter row and column of matrix 1 : ";
	cin >> row_1 >> col_1;
	float* matrix_1 = allocate(row_1, col_1);
	readm(matrix_1, row_1, col_1);

	int row_2, col_2;
	cout << "Enter row and column of matrix 2 : ";
	cin >> row_2 >> col_2;
	float* matrix_2 = allocate(row_2, col_2);
	readm(matrix_2, row_2, col_2);

	float* product = allocate(row_1, col_2);
	mulmatrix(matrix_1, row_1, col_1, matrix_2, col_2, product);

	system("pause");
	return 0;
}