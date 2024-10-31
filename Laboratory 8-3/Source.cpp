#include <iostream>
#include <string>

using namespace std;

int romanCharValue(char r);
int convertRomanToInt(const string& s);

int main() {
    string input;

    cout << "Enter Roman number or Q to quit: ";
    while (getline(cin, input)) {
        if (input == "Q" || input == "q") {
            break;
        }

        if (!input.empty()) {
            int value = convertRomanToInt(input);
            cout << input << " = " << value << endl;
        }

        cout << "Enter Roman number or Q to quit: ";
    }

    return 0;
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