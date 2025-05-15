/*//ios::beg -- calclate from beg of file
//ios::end -- calculate from end of file
//ios::cur -- offset is calculated from current position

//f1.seekp(32L ,ios::beg) -- set write posi to 33rd byte from beg of file
//f1.seekp(-10L,ios::end) -- set write posi to 11th byte from end of file
//f1.seekp(120,ios::cur)  -- set write posit to 123rd byte from current positio  of file

//f1.seekg(32L ,ios::beg) -- set read posi to 33rd byte from beg of file
//f1.seekg(-10L,ios::end) -- set read posi to 11th byte from end of file
//f1.seekg(120L,ios::cur)  -- set read posit to 123rd byte from current positio  of file

//f1.seekg(0L,ios::end)  -- sets the read position to the end of file

//TELLP AND TELLG
//tellp -- returns a long integer that is the current byte num of the file's write position
//tellg -- returns a long integer that is the curret byte num of the file's read position  --give seekg + 2
*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream f1;
    f1.open("shem.txt",ios::in);
    f1.seekg(0,ios::end);
    int i=f1.tellg();
    cout<<i;
    f1.close();
    return 0;
}
