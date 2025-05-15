#include <iostream>
#include <string>

using namespace std;

void digit_name(int number) {
    // Array of names for numbers 1 to 30
    string names[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                      "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                      "eighteen", "nineteen", "twenty", "twenty-one", "twenty-two", "twenty-three",
                      "twenty-four", "twenty-five", "twenty-six", "twenty-seven", "twenty-eight",
                      "twenty-nine", "thirty"};

    // Check if the number is in the valid range
    if (number >= 1 && number <= 30) {
        cout << names[number - 1] << endl; // Print the name of the number
    } else {
        cout << "digit error" << endl; // Print error message if number is out of range
    }
}

int main() {
    int n;
    int num;
    while(n != 0){
        cout<<"1.convert digit to num\n";
        cout<<"0.for exit\n";
        cin>>n;
        switch(n){
            case 1 : cout<<"enter value "<<endl;
                    cin>>num;
                   digit_name(num);
                   break;
             case 0: return 0;
             default : cout<<"enter valid choice"<<endl;      
        }
    }
   
    return 0;
}