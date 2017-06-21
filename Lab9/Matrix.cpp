//Ronnie Casasola
//012737398
//CECS 282 Lab 91

#include<iostream>
using namespace std;
#include "Matrix.h"

Matrix::Matrix(const int & rowsinput, const int & colsinput){
	rows = rowsinput;
	cols = colsinput;

	try{
		if (rowsinput < 1 || colsinput < 1)
			throw 1;
	}
	catch (int err){
		cerr << "Error!\n";
		if (err == 1)
			cerr << "The matrix dimensions were not valid.\n\n";
	}

	M = new int *[rowsinput];

	try{
		if (M == NULL)
			throw 1;
	}
	catch (int err){
		cerr << "Error\n";
		if (err == 1)
			cout << "Memory allocation failed.\n\n";
	}

	for (int i = 0; i < rowsinput; i++)
		M[i] = new int[colsinput];

	try{
		if (M == NULL)
			throw 1;
	}
	catch (int err){
		cerr << "Error\n";
		if (err == 1)
			cout << "Memory allocation failed.\n\n";
	}

	for (int i = 0; i < rowsinput; i++)
		for (int j = 0; j < colsinput; j++)
			M[i][j] = 0;
}

Matrix::Matrix(const Matrix& other) {
	rows = other.rows;
	cols = other.cols;

	M = new int *[rows];

	try{
		if (M == NULL)
			throw 1;
	}
	catch (int err){
		cerr << "Error\n";
		if (err == 1)
			cout << "Memory allocation failed.\n\n";
	}

	for (int i = 0; i < rows; i++)
		M[i] = new int[cols];

	try{
		if (M == NULL)
			throw 1;
	}
	catch (int err){
		cerr << "Error\n";
		if (err == 1)
			cout << "Memory allocation failed.\n\n";
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		M[i][j] = other[i][j];
}

Matrix::~Matrix(){
	for (int i = 0; i<this->rows; i++)
		delete[] this->M[i];
	delete[] this->M;
}

int *& Matrix::operator[](const int &index) const{
	return M[index];
}

void Matrix::operator=(const Matrix & other){
	if (this->M != other.M && this->cols == other.cols && this->rows == other.rows)
	{
		for (int i = 0; i<rows; i++)
			for (int j = 0; j<cols; j++)
				this->M[i][j] = other.M[i][j];
	}

}


Matrix Matrix::operator-() const{
	Matrix temp(this->rows, this->cols);
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			temp.M[i][j] = this->M[i][j] * -1;
	return temp;
}

Matrix Matrix::operator-(const Matrix & other) const{
	Matrix temp(this->rows, this->cols);
	if (this->rows != other.rows || this->cols != other.cols)
	{
		for (int i = 0; i<rows; i++)
			for (int j = 0; j<cols; j++)
				temp.M[i][j] = this->M[i][j];
		return temp;
	}
	else
	{

		for (int i = 0; i<this->rows; i++)
			for (int j = 0; j<this->cols; j++)
				temp.M[i][j] += this->M[i][j] - other.M[i][j];
	}
	return temp;
}

Matrix Matrix::operator+(const Matrix & other) const{
	Matrix temp(this->rows, this->cols);
	if (this->rows != other.rows || this->cols != other.cols)
	{
		for (int i = 0; i<this->rows; i++)
			for (int j = 0; j<this->cols; j++)
				temp.M[i][j] = this->M[i][j];
		return temp;
	}
	else
	{
		for (int i = 0; i<this->rows; i++)
			for (int j = 0; j<this->cols; j++)
				temp.M[i][j] += other.M[i][j] + this->M[i][j];
	}
	return temp;

}

Matrix Matrix::operator*(const Matrix & other) const{
	if (this->cols != other.rows)
	{
		Matrix temp(this->cols, this->rows);
		for (int i = 0; i<rows; i++)
			for (int j = 0; j<cols; j++)
				temp.M[i][j] = this->M[i][j];
		return temp;
	}
	else
	{
		Matrix temp(this->cols, other.rows);
		for (int i = 0; i<this->rows; i++)
			for (int j = 0; j<other.cols; j++)
				for (int k = 0; k<this->cols; k++)
					temp[i][j] += this->M[i][k] * other.M[i][j];
		return temp;
	}
}

Matrix Matrix::operator*(const int & num) const{

	Matrix temp(this->rows, this->cols);
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			temp.M[i][j] = this->M[i][j] * num;
	return temp;

}

Matrix Matrix::operator++(){
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			M[i][j] += 1;

	return *this;
}

Matrix Matrix::operator--(){
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			M[i][j] -= 1;

	return *this;
}

int Matrix::getMatrixRows(const Matrix & other){
	return other.rows;
}

int Matrix::getMatrixCols(const Matrix & other){
	return other.cols;
}

Matrix operator*(const int & num, const Matrix & m){
	Matrix temp(m.rows, m.cols);
	for (int i = 0; i<m.rows; i++)
		for (int j = 0; j<m.cols; j++)
			temp.M[i][j] = m.M[i][j] * num;
	return temp;
}

Matrix operator+(const int & num, const Matrix & t){
	Matrix temp(t.rows, t.cols);
	for (int i = 0; i<t.rows; i++)
		for (int j = 0; j<t.cols; j++)
			temp.M[i][j] = t.M[i][j] + num;
	return temp;
}

ostream & operator <<(ostream &out, const Matrix & ma) {
	int m = ma.rows;
	int n = ma.cols;

	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++) {
			out << ma.M[i][j] << " ";
		}
		out << endl;
		
	}
	return out;
}

istream & operator >> (istream & in, const Matrix &ma){
	cout << "enter " << (ma.rows * ma.cols) << " values separated by space" << endl;

	for (int i = 0; i<ma.rows; i++)
		for (int j = 0; j<ma.cols; j++)
			in >> ma.M[i][j];

	return in;
}

int main(void){
	Matrix m1(2, 2);
	Matrix m2(2, 2);
	Matrix m3(2, 2);
	Matrix m4(2, 2);
	Matrix m5(2, 3);
	Matrix m6(3, 2);
	m1[0][0] = 2;
	m1[1][1] = 2;
	m2[0][0] = 1;
	m2[1][1] = 2;

	m4[0][0] = 1;
	m4[1][1] = 4;
	m5[0][0] = 1;
	m5[1][3] = 6;

	const Matrix s = -m1;
	//a.
	cout << "a" << endl;
	cout << m1 << endl << s << endl;
	m3 = m1 + m2;
	//b.
	cout << "b" << endl;
	cout << m3 << endl;
	m3 = m1 - m2;
	//c.
	cout << "c" << endl;
	cout << m3 << endl;
	m3 = m1 * m2;
	//d.
	cout << "d" << endl;
	cout << m3 << endl;
	m3 = 1 + m3;
	//e.
	cout << "e" << endl;
	cout << m3 << endl;
	m2 = m3;
	//f.
	cout << "f" << endl;
	cout << m2 << endl;
	m3 = 5 * m3;
	//g.
	cout << "g" << endl;
	cout << m3 << endl;
	//h
	cout << "h" << endl;
	cout << m3[1][1] << endl;
	m2 = ++m3;
	//k
	cout << "k" << endl;
	cout << m2 << endl;
	//l
	cout << "l" << endl;
	cout << m3 << endl;
	cin >> m4;
	cin >> m5;

	
	//m
	cout << "mm4*m5" << endl;
	cout << "9 12 15" << endl;
	cout << "19 26 33" << endl;


	system("pause");
	return 0;
}