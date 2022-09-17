#include <iostream>
#include <string>

bool validateLuhn(std::string identifier);

int main(int argc, char* argv[])
{
    std::cout << validateLuhn(argv[1]) << '\n';
}

int getCharDigitValue(char c);
int sumDigits(int num);

bool validateLuhn(std::string identifier)
{
    int sum = 0;
    bool shouldDouble = false;

    for (int i = 0, n = identifier.length(); i < n; i++) {
        int num = getCharDigitValue(identifier[i]);
        if (shouldDouble) {
            num *= 2;
        }
        sum += sumDigits(num);
        shouldDouble = !shouldDouble;
    }
    return sum % 10 == 0;
}

// preconditions: '0' <= c <= '9'
int getCharDigitValue(char c)
{
    return c - '0';
}

// preconditions: 0 <= num < 20
int sumDigits(int num)
{
    if (num >= 10) {
        return 1 + num % 10;
    }
    return num;
}
