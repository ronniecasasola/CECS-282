#include <time.h>
#include "CarWash.h"
#include <queue>
#include <stdlib.h>

using namespace std;
using namespace CarWash;

int main()
{
	queue<int> q;
	int cur, next, wash_time, s_len;
	double a_rate;
	char answer[2];

		cout << "\nSeconds to wash one car: ";
		cin >> wash_time;
		cout << "\nProbability of customer arrival during a second: ";
		cin >> a_rate;
		cout << "\nTotal simulation seconds: ";
		cin >> s_len;
		
		

		wash_machine car_wash(wash_time);
		arrival car_rate(a_rate);
		averager cal;

		srand(time(NULL));

		for (cur = 1; cur<s_len + 1; cur++)
		{
			if (car_rate.is_car_coming())
				q.push(cur);

			if (!car_wash.is_busy() && !q.empty())
			{
				next = q.front();
				q.pop();
				cal.plus_next_number(cur - next);
				car_wash.start_washing();
			}

			car_wash.one_second();
		}

		cout << "\nCustomers served: " << cal.how_many_cars() << endl;
		cout << "\nThe average wait: " << cal.average_time() << endl;

		system("pause");
		return 0;

}