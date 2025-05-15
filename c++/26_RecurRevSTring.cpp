#include <iostream>
#include <string.h>
using namespace std;
int i = 0;
string recur(string str, int size)
{
   if (i < size /2)
   {
      char temp = str[i];
      str[i] = str[size - i - 1];
      str[size - i - 1] = temp;
      i++;
       return recur(str, size);
   }
   else
   {
      return str;
   }
}
int main()
{
   string str;
   getline(cin,str);
   int n = str.length(); // str.size();
   cout << recur(str, n) << endl;
   return 0;
}