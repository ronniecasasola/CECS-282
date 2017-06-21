//Ronnie Casasola
//012737398
//CECS 282 Lab 9


#ifndef Matrix_h
#define Matrix_h
#include <iostream>
using namespace std;

typedef int matrixData;

class Matrix
{
private:
	int rows;
	int cols;
	matrixData **M;

public:
	Matrix(const int &rows, const int &cols);
	Matrix(const Matrix &other);
	~Matrix();
	int* & operator[](const int &index) const;
	void operator=(const Matrix &other);
	Matrix operator -()const;
	Matrix operator -(const Matrix &other)const;
	Matrix operator +(const Matrix &other)const;
	Matrix operator *(const Matrix &other)const;
	Matrix operator *(const int &num)const;
	Matrix operator++();
	Matrix operator--();
	int getMatrixRows(const Matrix &other);
	int getMatrixCols(const Matrix &other);
	friend Matrix operator *(const int & num, const Matrix &m);
	friend Matrix operator +(const int &num, const Matrix &t);
	friend ostream &operator<<(ostream &os, const Matrix &m);
		friend istream& operator >> (istream& in, const Matrix& m);
};
#endif
