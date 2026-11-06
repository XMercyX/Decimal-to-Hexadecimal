/*
A program that takes user input as hexadecimal values and applys mathematical operations to them
Steps:
1. Take user input.
2. Read user input.
    a. Take input
    b. Remove all whitespace
3. decipher user input
4. calculate final result
5. output result
6. end program
*/

// Includes
#include <iostream>
#include <cctype> // https://cplusplus.com/reference/cctype/
#include <stdexcept>
#include <cmath>
#include <cstdint>

// "using"s
using std::cout;
using std::cin;
using str = std::string;

// Const Variables

// Hex values: 0123456789abcdef
const char HEX_CHARS[] = {
    '0','1','2','3','4','5','6','7','8','9',
    'a','b','c','d','e','f'
};

// Global Variables



// Function Definitions


bool isValidChar(char C);
bool validString(str STRING);

str removeWS(str S);
str makeStrLower(str u);
str reverse(str STRING);

int64_t convertToDecimal(str INPUT);

int convertCharacterToDecimal(char C);


// Main function
int main(){
    str userInput;
    cout << "Write an equation in Hex: ";
    std::getline(cin, userInput); 
    // Gets the entire line inputted by the user
    userInput = makeStrLower(removeWS(userInput));

    if(validString(userInput)){
        cout << userInput << '\n';

        int64_t FINAL;
        FINAL = convertToDecimal(userInput);
        cout << FINAL << '\n';





    } else {
        //throw std::runtime_error("NOT VALID STRING");
    }
    return 0;
}

// Returns true if the inputted char can be used
// in hexadecimal math
// SEE HEX_CHARS
bool isValidChar(char C){
    for(int i = 0; i < sizeof(HEX_CHARS)/sizeof(char); i++){
        if(HEX_CHARS[i] == C){
            return true;
        } else {
            //throw std::runtime_error("invalid char provided: " + C);
        }
    }
    return false;
}

bool validString(str STRING){
    for(int i = 0; i < STRING.length(); i++){
        if(!isValidChar(STRING[i])){
            return false;
        }
    }
    return true;
}

// Removes all whitespace from a string
str removeWS(str S){
    str ret = "";
    for(int i = 0; i < S.length(); i++){
        if (S[i] != ' '){
            ret = ret + S[i];
        }
    }
    return ret;
}

// Takes in a string of hex values and returns
// a decimal double value.
int64_t convertToDecimal(str INPUT){
    // Go thru each character from the final one to the first one
    // and add them up.
    // Each new place is 16x the previous
    // Left is the greatest
    // 10000 in hex = 65536 in decimal
    // a*16^3 + b*16^2 + c*16^1 + d*16^0 = (abcd) in hex
    // a_n * 16^n-1 + a_(n-1) * 16^(n-2) ... + a_1

    int length = INPUT.length(); // outputs final index + 1
    str rev = reverse(INPUT); // now index 0 is also exponent 0
    int64_t output = 0;
    for(int i = 0; i < length; i++){
        output += convertCharacterToDecimal(rev[i]) * (pow(16,i));
        //cout << output << '\n';
    }
    return output; // Returns the wrong value.
}

// Makes all characters in a string into lowercase
str makeStrLower(str u){
    str _final;
    for(int i = 0; i < u.length(); i++){
        _final += (char)tolower(u[i]);
    }
    return _final;
}

int convertCharacterToDecimal(char C){
    switch(C){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'a': return 10;
        case 'b': return 11;
        case 'c': return 12;
        case 'd': return 13;
        case 'e': return 14;
        case 'f': return 15;
    }
    return -1;
}

str reverse(str STRING){
    str R;
    int len = STRING.length() - 1;
    for(int i = 0; i <= len; i++){
        R += STRING.at(len - i);
    }
    return R;
}




