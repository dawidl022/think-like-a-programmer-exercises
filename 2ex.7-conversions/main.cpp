#include <iostream>
using std::cin;
using std::cout;

enum sourceState {
    UNDETERMINED,
    BINARY,
    OCTAL,
    DECIMAL,
    HEXADECIMAL,
};

bool isDigit(char c);
void decToBase(int decimal, int base);
void printStandardBases(int num);
void printFlagBase(int num, char baseFlag);

int main(int argc, char* argv[])
{
    sourceState source = UNDETERMINED;
    int number = 0;

    for (char c = cin.get(); c != '\n'; c = cin.get()) {
        switch (source) {
        case UNDETERMINED:
            if (c == 'b') {
                source = BINARY;
            }
            else if (c == 'o') {
                source = OCTAL;
            }
            else if (c == 'x') {
                source = HEXADECIMAL;
            }
            else if (c != '0' && isDigit(c)) {
                source = DECIMAL;
                number = c - '0';
            }
            break;

        case BINARY:
            number <<= 1;
            number += c - '0';
            break;

        case OCTAL:
            number <<= 3;
            number += c - '0';
            break;

        case DECIMAL:
            number *= 10;
            number += c - '0';
            break;

        case HEXADECIMAL:
            number *= 16;
            if (isDigit(c)) {
                number += c - '0';
            }
            else {
                c |= 32; // convert letter to lowercase
                number += c - 'a' + 10;
            }
            break;
        }
    }

    if (argc == 1 || argv[1][0] == '\0') {
        printStandardBases(number);
    }
    else {
        if (argv[1][0] == '-') {
            printFlagBase(number, argv[1][1]);
        }
        else {
            int base = 0;
            for (int i = 0; argv[1][i] != '\0'; i++) {
                base *= 10;
                base += argv[1][i] - '0';
            }
            decToBase(number, base);
        }
    }

    return 0;
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

char intToChar(int num);

void decToBase(int decimal, int base)
{
    if (decimal == 0) {
        cout << 0 << '\n';
        return;
    }

    int i = 1;
    for (; i <= decimal; i *= base) {}

    i /= base;

    for (; i > 0; i /= base) {
        if (decimal >= i) {
            int integral = decimal / i;
            decimal -= integral * i;

            cout << intToChar(integral);
        }
        else {
            cout << 0;
        }
    }

    cout << '\n';
}

char intToChar(int num)
{
    if (num < 10) {
        return num + '0';
    }
    return num + 'a' - 10;
}

void printStandardBases(int num)
{
    cout << "bin: ";
    decToBase(num, 2);

    cout << "oct: ";
    decToBase(num, 8);

    cout << "dec: ";
    decToBase(num, 10);

    cout << "hex: ";
    decToBase(num, 16);
}

void printFlagBase(int num, char baseFlag)
{
    switch (baseFlag) {
    case 'b':
        decToBase(num, 2);
        break;

    case 'o':
        decToBase(num, 8);
        break;

    case 'd':
        decToBase(num, 10);
        break;

    case 'x':
        decToBase(num, 16);
        break;
    }
}
