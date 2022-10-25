#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//This function converts numbers to Roman numbers;
string numbersToRoman(int input) {
    
    string romans[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int numbers[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    string output = "";
    
    for (int i = 0; i < 13; i++){
        while (input >= numbers[i]){
            output += romans[i];
            input -= numbers[i];
        }
    }
    return output;
}



int main()
{
    // Just for test
    int number;
    string endNumberInRoman;
    cout << "Enter number: ";
    cin >> number;
    endNumberInRoman = numbersToRoman(number);
    cout << "This is end number in roman: " << endNumberInRoman << endl;

    return 0;
}

