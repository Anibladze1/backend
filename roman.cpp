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


int romanToInteger(string roman) {
	unordered_map<char, int> counter;
    int result = 0;
    if(roman.length()==0) {
        cout << "Incorrect input length 0" << endl;
        return -1;
    }
    if(roman.length()==1) {
        return vals[roman[0]];
    }
    if(count(roman.begin(),roman.end(),'V')>1) {
        cout << "Incorrect input V is more than 3 " << endl;
        return -1;
    }

    char last = roman[0];
    result+=vals[last];
    for(int i = 1;i<roman.length();i++) {
        if(counter.find(roman[i])==counter.end()) {
            counter[roman[i]] = 1;
            if(vals[roman[i]]>vals[last]&&afterValid.find(last)!=afterValid.end()&&count(afterValid[last].begin(),afterValid[last].end(),roman[i])>0) {
                result+= vals[roman[i]]-2*vals[last];
                last = roman[i];
                continue;
            } else if(vals[roman[i]]>vals[last]&&afterValid.find(last)!=afterValid.end()&&count(afterValid[last].begin(),afterValid[last].end(),roman[i])==0) {
                cout << "Incorrect outputo" << endl;
                return -1;
            } else if(vals[roman[i]]>vals[last]&&afterValid.find(last)==afterValid.end()) {
                cout << "Incorrect outout" << endl;
                return -1;
            }
            result+=vals[roman[i]];
            last = roman[i];
            
        } else {
            if(counter[roman[i]]>3) {
                cout <<"Incorrect input" << endl;
                return -1;
            }
            counter[roman[i]]++;
            if(vals[roman[i]]>vals[last]&&afterValid.find(last)!=afterValid.end()&&count(afterValid[last].begin(),afterValid[last].end(),roman[i])>0) {
                result+= vals[roman[i]]-2*vals[last];
                last = roman[i];
                continue;
            } else if(vals[roman[i]]>vals[last]&&afterValid.find(last)!=afterValid.end()&&count(afterValid[last].begin(),afterValid[last].end(),roman[i])==0) {
                cout << "Incorrect outputo" << endl;
                return -1;
            } else if(vals[roman[i]]>vals[last]&&afterValid.find(last)==afterValid.end()) {
                cout << "Incorrect outout" << endl;
                return -1;
            }
            result+=vals[roman[i]];
            last = roman[i];

        }
    }
    return result;

}









int main() {

    cout << romanToInteger("XLIX") << endl;



    


        


    

    



    return 0;
}