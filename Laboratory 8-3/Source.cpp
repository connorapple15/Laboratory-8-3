#include <iostream>
#include <string>

using namespace std;

int romanCharValue(char r);
int convertRomanToInt(const string& s);

int main() {
    cout << "Testing romanCharValue function:\n";
    cout << "I = " << romanCharValue('I') << endl; 
    cout << "V = " << romanCharValue('V') << endl; 
    cout << "X = " << romanCharValue('X') << endl; 
    cout << "L = " << romanCharValue('L') << endl; 
    cout << "C = " << romanCharValue('C') << endl; 
    cout << "D = " << romanCharValue('D') << endl; 
    cout << "M = " << romanCharValue('M') << endl; 
    ;
    cout << "MCMLXII = " << convertRomanToInt("MCMLXII") << endl; 
    cout << "MDCCCLXXXVIII = " << convertRomanToInt("MDCCCLXXXVIII") << endl; 

    return 0;
}

int romanCharValue(char r) {
    switch (r) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0; 
    }
}
int convertRomanToInt(const string& s) {
    int total = 0;
    int length = s.length();

    for (int i = 0; i < length; i++) {
        if (i + 1 == length || romanCharValue(s[i]) >= romanCharValue(s[i + 1])) {
            total += romanCharValue(s[i]);
        }
        else {
            total -= romanCharValue(s[i]);
        }
    }
    return total;
}