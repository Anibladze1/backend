#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <bits/stdc++.h>


using namespace std;

unordered_map<char, int> vals{ {'I',1},{'V',5},{'X',10},{'L',50},{'C',100}};
unordered_map<char,vector<char>> afterValid{{'I',{'V','X'}},{'X',{'C','L'}}};

// რომაულიდან არაბულში გადამყვანი ფუნქცია
// ასევე ამოწმებს რომაული რიცხვების სისწორეს
int romanToInteger(string roman) {
	unordered_map<char, int> counter;
    unordered_map<char,int>::iterator it;
    int result = 0;
    if(roman.length()==0) {
        cout << "Input can't be length 0" << endl;
        return -1;
    }
    if(roman.length()==1 && vals.find(roman[0])==vals.end()) {
        return -1;
    } 
    if(count(roman.begin(),roman.end(),'V')>1) {
        cout << "Incorrect input V is more than 1 time " << endl;
        return -1;
    }
    
    if(roman.length()==1) {
        return vals[roman[0]];
    }

    char last = roman[0];
    result+=vals[last];
    counter[roman[0]] = 1;
    if(vals.find(roman[0])==vals.end()) {
        return -1;
    }
    for(int i = 1;i<roman.length();i++) {
        if(vals.find(roman[i])==vals.end()) {
            cout << "Incorrect input" << endl;
            return -1;
        }
        if(counter.find(roman[i])==counter.end()) {
            counter[roman[i]] = 1;
            if(vals[roman[i]]>vals[last]&&afterValid.find(last)!=afterValid.end()&&count(afterValid[last].begin(),afterValid[last].end(),roman[i])>0) {
                result+= vals[roman[i]]-2*vals[last];
                last = roman[i];
                continue;
            } else if(vals[roman[i]]>vals[last]&&afterValid.find(last)!=afterValid.end()&&count(afterValid[last].begin(),afterValid[last].end(),roman[i])==0) {
                cout << "Incorrect input" << endl;
                return -1;
            } else if(vals[roman[i]]>vals[last]&&afterValid.find(last)==afterValid.end()) {
                cout << "Incorrect input" << endl;
                return -1;
            }
            result+=vals[roman[i]];
            last = roman[i];
            
        } else {
            counter[roman[i]]++;
            if(counter[roman[i]]>3) {
                cout <<"Incorrect input" << endl;
                return -1;
            }
            
            if(vals[roman[i]]>vals[last]&&afterValid.find(last)!=afterValid.end()&&count(afterValid[last].begin(),afterValid[last].end(),roman[i])>0) {
                result+= vals[roman[i]]-2*vals[last];
                last = roman[i];
                continue;
            } else if(vals[roman[i]]>vals[last]&&afterValid.find(last)!=afterValid.end()&&count(afterValid[last].begin(),afterValid[last].end(),roman[i])==0) {
                cout << "Incorrect input" << endl;
                return -1;
            } else if(vals[roman[i]]>vals[last]&&afterValid.find(last)==afterValid.end()) {
                cout << "Incorrect input " << endl;
                return -1;
            }
            result+=vals[roman[i]];
            last = roman[i];

        }
    }
    return result;

}
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

// თუ რიცხვი უარყოფითია გამოიტანს მინუსს.
    if (input < 0){
        input = abs(input);
        
        cout << "Result is: -";
    } 

 // თუ რიცხვი დადებითია დაბეჭდავს ჩვეულებრივად.
    else {
        cout << "Result is: ";
    }

    for (auto i = Converter.rbegin(); i != Converter.rend(); i++){
        while (input >= i -> first){
            output += i -> second;
            input -= i -> first;
        }
    }
    
    return output;
}





// კალკულატორის ფუნქცია, რომელიც ასევე იღებს ინფუთებად ოპერატორებს.
string calculator (){
    
    string operand;
    string romanNumber;

    cout << "Enter Roman Number: ";
    cin >> romanNumber;
    if(romanToInteger(romanNumber)==-1) {
        return "Error";
    }
    int result = romanToInteger(romanNumber);
    cout << "Enter Operator: ";
    cin >> operand;


    
    while(operand != "exit") {   

        cout << "Enter Roman Number: ";
        cin >> romanNumber;
        if(romanToInteger(romanNumber)==-1) {
            return "Error";
        }

        if (operand == "+") {
            result=result + romanToInteger(romanNumber);
        } 
        
        else if (operand == "-"){
            
            result=result - romanToInteger(romanNumber);
            }
            
        else if (operand == "*") {
                result=result * romanToInteger(romanNumber);
            }
            
        else if (operand == "/") {
                
                result=result/romanToInteger(romanNumber);
            }

        else {
                cout << "Wrong Operator" << endl;
            }
    
        cout << "Enter Operator: ";
        cin >> operand;

    }        
    
    return numbersToRoman(result);    

}
int main (){

    // საბოლოო რიცხვი რომაულ ფორმატში
    cout << calculator() << endl;
    
   
}