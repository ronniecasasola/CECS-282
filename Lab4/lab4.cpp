//Ronnie Casasola
//012737398
//CECS 282 Lab 4

#include<iostream>
#include<cstring>
using namespace std;

void transform(char *raw, char *testStr);
bool testPalindrome(char *str);

int main()
{

	bool done = true;

	while (done){

		char str[80];
		char convertedStr[80];

		cout << "Enter String: (press enter to quit) ";
		gets_s(str);

		

		transform(str, convertedStr);

		if (strlen(str) == 0) {
			done = false;
			break;
		}

		else {
			bool res = testPalindrome(convertedStr);
			if (res) {
				cout << "\nEntered String is Palindrome" << endl;
				cout << endl;
			}
			else {
				cout << "\nEntered String is not a Palindrome" << endl;
				cout << endl;
			}

		}
	}
	system("pause");
	return 0;
}

void transform(char *raw, char *testStr) {

	int strlength = strlen(raw);
	int front = 0;
	for (int i = 0; i < strlength; i++)
	{
		raw[i] = toupper(raw[i]); 
	}
	for (int i = 0; i < strlength; i++)
	{
		if (isalpha(raw[i])) {
			testStr[front] = raw[i];
			front++;
		}
	}
}

bool testPalindrome(char *str) {
	bool result = true;
	int strlength = strlen(str); 
	int front = 0, rear = strlength - 1;
	for (int i = 0; i< strlength / 2; i++) { 
		if (str[front] != str[rear]) { 
			result = false;
			break;
		}
	}
	return result; 
}