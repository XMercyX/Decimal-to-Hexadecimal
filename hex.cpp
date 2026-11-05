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
str removeWS(str S);
void convertToDecimal(str INPUT);
str makeStrLower(str u);

// Main function
int main(){
    str userInput;
    cout << "Write an equation in Hex:\t";
    std::getline(cin, userInput); 
    // Gets the entire line inputted by the user

    userInput = removeWS(userInput);

    cout << makeStrLower(userInput) << '\n';




    return 0;
}

// Returns true if the inputted char can be used
// in hexadecimal math
// SEE HEX_CHARS
bool isValidChar(char C){
    for(int i = 0; i < sizeof(HEX_CHARS)/sizeof(char); i++){
        if(HEX_CHARS[i] == C){
            return true;
        }
    }
    return false;
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
void convertToDecimal(str INPUT){
    // Go thru each character from the final one to the first one
    // and add them up.
    // Each new place is 16x the previous
    // Left is the greatest
    // 10000 in hex = 65536 in decimal
}

// Makes all characters in a string into lowercase
str makeStrLower(str u){
    str _final;
    for(int i = 0; i < u.length(); i++){
        _final += (char)tolower(u[i]);
    }
    return _final;
}