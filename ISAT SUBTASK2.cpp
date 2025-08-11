//HLONGWANE FUNDISWA
//0204020990089
//L3B subtask 2
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

// Function declarations
string decimalToBinary(int decimalValue);
int binaryToDecimal(string binaryValue);
int hexadecimalToDecimal(string hexValue);
string decimalToHexadecimal(int decimalValue);
int generateRandomInt();

// Global variables
int decimalValue;
string binaryValue;
string hexValue;
int randomValue;

// Function to convert decimal to binary
string decimalToBinary(int decimalValue)
{
    string binary = "";
    if (decimalValue == 0) return "0";

    while (decimalValue > 0)
    {
        binary = to_string(decimalValue % 2) + binary;
        decimalValue /= 2;
    }
    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(string binaryValue)
{
    int decimal = 0;
    int base = 1;

    for (int i = binaryValue.length() - 1; i >= 0; i--)
    {
        if (binaryValue[i] == '1')
            decimal += base;
        else if (binaryValue[i] != '0')
        {
            cout << "Invalid binary number." << endl;
            return -1;
        }
        base *= 2;
    }
    return decimal;
}

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(string hexValue)
{
    int decimal = 0;
    int base = 1;

    for (int i = hexValue.length() - 1; i >= 0; i--)
    {
        char ch = toupper(hexValue[i]);
        if (ch >= '0' && ch <= '9')
        {
            decimal += (ch - '0') * base;
        }
        else if (ch >= 'A' && ch <= 'F')
        {
            decimal += (ch - 'A' + 10) * base;
        }
        else
        {
            cout << "Invalid hexadecimal number." << endl;
            return -1;
        }
        base *= 16;
    }
    return decimal;
}

// Function to convert decimal to hexadecimal
string decimalToHexadecimal(int decimalValue)
{
    int remainder;
    string hex = "";

    if (decimalValue == 0) return "0";

    while (decimalValue > 0)
    {
        remainder = decimalValue % 16;
        if (remainder < 10)
            hex = to_string(remainder) + hex;
        else
            hex = char('A' + remainder - 10) + hex;

        decimalValue = decimalValue / 16;
    }

    return hex;
}

// Function to generate a random number between 1 and 99
int generateRandomInt()
{

}

int main()
{
    int menuSelection = 0;

    cout << "Conversion Menu:" << endl;
    printf("1.  Convert decimal to binary\n");
    printf("2.  Convert binary to decimal\n");
    printf("3.  Convert hexadecimal to decimal\n");
    printf("4.  Convert decimal to hexadecimal\n");
    printf("5.  Demo (generate and convert random integers to binary)\n");
    printf("6.  Exit\n");

    while (menuSelection < 7)
    {
        cout << "\nMake your choice (1 to 6): ";
        cin >> menuSelection;

        if (menuSelection == 1)
        {
            cout << "Enter a DECIMAL number: ";
            cin >> decimalValue;
            cout << "Binary representation: " << decimalToBinary(decimalValue) << endl;
        }
        else if (menuSelection == 2)
        {
            cout << "Enter a BINARY number: ";
            cin >> binaryValue;
            cout << "Decimal representation: " << binaryToDecimal(binaryValue) << endl;
        }
        else if (menuSelection == 3)
        {
            cout << "Enter a HEXADECIMAL number: ";
            cin >> hexValue;
            cout << "Decimal representation: " << hexadecimalToDecimal(hexValue) << endl;
        }
        else if (menuSelection == 4)
        {
            cout << "Enter a DECIMAL number: ";
            cin >> decimalValue;
            cout << "Hexadecimal representation: " << decimalToHexadecimal(decimalValue) << endl;
        }
        else if (menuSelection == 5)
        {
            randomValue = generateRandomInt();
            cout << "Generated random integer: " << randomValue << endl;
            cout << "Binary representation: " << decimalToBinary(randomValue) << endl;
        }
        else if (menuSelection == 6)
        {
            cout << "Exiting the program." << endl;
            exit(0);
        }
        else
        {
            cout << "Invalid selection. Try again." << endl;
        }
    }

    return 0;
}

