#include <iostream>
using namespace std;
class dayname
{
int day;
public:
	static string month[12];
	static int dmonth[12] ;
	dayname(int d){	day = d;}
	void print()
	{
		int sum = 0;
		int idx;
		for (int i = 0; i < 12; i++)
		{
			sum = sum + dmonth[i];
			idx = i;
			if (sum>=day)
			{
				break;
			}
		}	
		int a = dmonth[idx] + day - sum;
		cout << month[idx] << " " << a;
	}
};
// Static member initialization outside the class
string dayname::month[12] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int dayname::dmonth[12] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
int main()
{
	int x;
	cout << "enter no of days:";
	cin >> x;
	dayname y(x);
	y.print();
	return 0;
}