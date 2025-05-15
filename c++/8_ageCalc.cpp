#include <iostream>
using namespace std;

void findAge(int cdd, int cmm, int cyy, int bdd, int bmm, int byy)
{

	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (byy % 4 == 0 || cyy % 4 == 0)
	{
		month[1] = 29;
	}

	if (bdd > cdd)
	{
		cdd = cdd + month[bmm - 1];
		cmm = cmm - 1;
	}

	if (bmm > cmm)
	{
		cyy = cyy - 1;
		cmm = cmm + 12;
	}
	int calculated_date = cdd - bdd;
	int calculated_month = cmm - bmm;
	int calculated_year = cyy - byy;
	cout << calculated_year << "years " << calculated_month << "months " << calculated_date << "days" << endl;
}
int main()
{
	int cdd;
	int cmm;
	int cyy;
	cout << "enter current date: month: year: ";
	cin >> cdd >> cmm >> cyy;

	int bdd;
	int bmm;
	int byy;
	cout << "enter birth date: month: year: ";
	cin >> bdd >> bmm >> byy;
	findAge(cdd, cmm, cyy, bdd, bmm, byy);

	return 0;
}