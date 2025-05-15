#include <iostream>
using namespace std;
int main()
{
   int n;
   int even = 0;
   int odd = 0;
   cout << "enter the size :\n";
   cin >> n;
   int arr[n];
   int ev[n];
   int od[n];
   int evod[n];
   cout << "enter the elements of array\n";
   int cnt;
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
      cnt = arr[i] % 2;
      if (cnt == 0)
      {
         ev[even] = arr[i];
         even++;
      }

      else
      {
         od[odd] = arr[i];
         odd++;
      }
   }

   for (int i = 0; i < n; i++)
   {
      if (i < odd)
      {
         cout << od[i] << " ";
      }
      else
      {
         cout << ev[i - odd] << " ";
      }
   }

   return 0;
}