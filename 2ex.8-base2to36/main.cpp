#include <iostream>
#include <stdio.h>
using std::cin;
using std::cout;

int parseInt(char* str);
bool isOutOfRange(int n);
int baseToDec(int base);
void printDecToBase(int number, int base);

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "usage: ./main <source-base> <target-base>\n";
        return 2;
    }

    int source = parseInt(argv[1]);
    int target = parseInt(argv[2]);

    if (isOutOfRange(source) || isOutOfRange(target)) {
        cout << "Can only convert from and to a base between 2 and 36\n";
        return 2;
    }

    int decimal = baseToDec(source);
    if (decimal == -1) {
        return 1;
    }
    printDecToBase(decimal, target);
}

int parseInt(char* str)
{
    int number = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        number *= 10;
        number += str[i] - '0';
    }

    return number;
}

bool isOutOfRange(int n)
{
    return n < 2 || n > 36;
}

bool isDigit(char c);
int charToInt(char c);
void clearLine();

int baseToDec(int base)
{
    int number = 0;

    for (char c = cin.get(); c != '\n'; c = cin.get()) {
        number *= base;
        int digit = charToInt(c);

        if (digit >= base) {
            clearLine();
            printf("invalid digit '%c' for base-%d number\n", c, base);
            return -1;
        }
        number += digit;
    }

    return number;
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

int charToInt(char c)
{
    if (isDigit(c)) {
        return c - '0';
    }
    c |= 32; // convert letter to lowercase
    return c - 'a' + 10;
}

void clearLine()
{
    cout << "\33[2K\r";
}

char intToChar(int num);

void printDecToBase(int decimal, int base)
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
