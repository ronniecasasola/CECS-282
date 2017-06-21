#include <iostream>
using namespace std;
int main() {
	int x = 10;
	int *p = &x;
	int **q = &p;

	cout << x << endl;
	cout << p << endl;
	cout << *q << endl;
	system("pause");
	return 0;

}