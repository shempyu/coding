#include <iostream>
using namespace std;
class date
{
private:
  int dd, mm, yy;

public:
  date()
  {
    dd = 0;
    mm = 0;
    yy = 0;
  }
  void setdate(int day, int month, int year)
  {
    dd = day;
    mm = month;
    yy = year;
  }
  void show()
  {
    cout << dd << " " << mm << " " << yy << endl;
  }
  int leapyear()
  {
    if (yy % 4 == 0)
      return 1;
    else
      return 0;
  }
  int monthmaxday()
  {
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (leapyear() && mm == 2)
      return 29;
    else
      return month[mm - 1];
  }
  void operator++()
  {
    ++dd;
    if (dd > monthmaxday())
    {
      dd = 1;
      ++mm;
    }
    if (mm > 12)
    {
      mm = 1;
      yy++;
    }
  }
};
int main()
{
  date d1, d2;
  d1.setdate(29, 3, 2020);
  ++d1;
  d1.show();
  d2.setdate(28, 2, 2021);
  ++d2;
  d2.show();
}