#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

//This function converts numbers to Roman numbers;
string numbersToRoman(int input) {

    map <int, string> Converter ;

    Converter[1] = "I";
    Converter[4] = "IV";
    Converter[5] = "V";
    Converter[9] = "IX";
    Converter[10] = "X";
    Converter[40] = "XL";
    Converter[50] = "L";
    Converter[90] = "XC";
    Converter[100] = "C";
    Converter[400] = "CD";
    Converter[500] = "D"; 
    Converter[900] = "CM";
    Converter[1000] = "M";
    
    string output = "";
    for (auto i = Converter.rbegin(); i != Converter.rend(); i++){

        while (input >= i -> first){
            output += i -> second;
            input -= i -> first;
        }
    }
    
    return output;
}


int main (){
    cout << numbersToRoman(169) << endl;
}
