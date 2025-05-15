#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char c;
    ifstream f1("shem.txt");
    ofstream f2("shem2.txt");
    if (f1.fail() || f2.fail())
    {
        cout << "failed\n";
    }
    else
    {
        while (!f1.eof())
        {
            f1.get(c);
            f2.put(c);
        }
        f1.close();
        f2.close();
    }
    cout << "completed\n";
    return 0;
}