#include <iostream>
using namespace std;
int rev = 0;
int recur(int n)
{
   rev = rev * 10 + n % 10;
   n = n / 10;
   if (n != 0)
      recur(n);
   else
      return rev;
}
int main()
{
   int n;
   cout << "enter a number\n";
   cin >> n;
   cout << recur(n);
   return 0;
}