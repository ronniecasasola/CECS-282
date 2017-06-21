#include<string>

#ifndef UPDATE_H_
#define UPDATE_H_H
class upDate
{
public:
	upDate();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Construct and allocated memory for upDate object and initialize its value to 5/11/1959.
	//	_Increase dateCount by 1.

	upDate(int M, int D, int Y);
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Construct and allocated memory for upDate object and initialize its value with a given date if it's a valid date else initialize object's value to 5/11/1959.
	//	_Increase dateCount by 1.

	static int daysInMonth(int m, int y);

	upDate(const upDate &d);
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Copy the value stored inside object d into this object with allocated memory space.
	//	_Increase dateCount by 1.

	~upDate();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Delete the allocated memory space used to store date of this object
	//	_Decrease dateCount by 1

	void setDate(int M, int D, int Y);
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Set the date of this object into a given date if the given date is valid else throw an error message.

	int getMonth() const;
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return integer month.

	int getDay() const;
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return integer day.

	int getYear() const;
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return integer year.

	std::string getMonthName();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return string month

	void operator=(const upDate &d);
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Copy the date of d object into the date of this object.

	upDate operator+ (const int i);
	//Precondition:
	//	_i is positive integer.
	//Postcondition:
	//	_Return the date of this object increased by i day/days.

	upDate operator-(const int i);
	//Precondition:
	//	_i is positive integer.
	//Postcondition:
	//	_Return the date of this object decreased by i day/days.

	int operator-(const upDate&d);
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return the sum of this date and d's date.

	friend upDate operator+ (const int i, const upDate& d);
	//Precondition:
	//	_i is positive integer.
	//Postcondition:
	//	_Return the date of d object increased by i day/days.

	upDate operator++(int);
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return the date of this object increased by 1

	upDate operator ++();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return the original date of this object then increase the date by 1.

	upDate operator--(int);
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return the date of this object decreased by 1

	upDate operator --();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return the original date of this object then decrease the date by 1.

	friend std::ostream& operator<< (std::ostream& os, const upDate& d);
	//Precondition:
	//	_None.f
	//Postcondition:
	//	_Print date of d object in the following format: Month/Day/Year. Ex: 5/11/1959.

	long julian() const;
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return the julian date of this object

	bool operator==(const upDate&d);
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return ture if date of this object and date of d object is the same else return false.

	bool operator<(const upDate&d);
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return ture if date of this object is less than the date of d object else return false.

	bool operator>(const upDate&d);
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return ture if date of this object is bigger than the date of d object else return false.

	static int GetDateCount();
	//Precondition:
	//	_None.
	//Postcondition:
	//	_Return the number of upDate object still existed.

private:
	int * date;
	//Precondition:
	//	_None
	//Postcondition:
	//	_Stored the month, day, and year of this object.

	static int dateCount;
	//Precondition:
	//	_dateCount must be zero
	//Postcondition:
	//	_dateCount will keep track on how many upDate still existed

	static void JulianToGregorian(int* list, int JD);
	//Precondition:
	//	_list must have an allocated memory location to stored three integer values.
	//Postcondition:
	//	_Return an array that stored integer month at index 0, integer month at index 1, and integer year at index 2.

	static double GregorianToJulian(int M, int D, int Y);
	//Precondition:
	//	_Month, day, and year must be a combination of valid date.
	//Postcondition:
	//	_Return a julian date represented by the given gregorian date.
};
#endif