#include <iostream>

using std::cin;
using std::cout;

void validateLuhn();

int main()
{
    validateLuhn();

    return 0;
}

int doubleDigitValue(int digit);

void validateLuhn()
{
    int i;
    char digit;
    int evenChecksum = 0;
    int oddChecksum = 0;
    cout << "Enter a number: ";

    for (i = 0, digit = cin.get(); digit != '\n'; i++, digit = cin.get()) {
        int num = digit - '0';
        if (i % 2 == 0) {
            evenChecksum += doubleDigitValue(num);
            oddChecksum += num;
        }
        else {
            evenChecksum += num;
            oddChecksum += doubleDigitValue(num);
        }
    }
    int checksum = i % 2 == 0 ? evenChecksum : oddChecksum;

    cout << "Checksum is " << checksum << ".\n";

    if (checksum % 10 == 0) {
        cout << "Checksum is divisible by 10. Valid.\n";
    }
    else {
        cout << "Checksum is not divisible by 10. Invalid.\n";
    }
}

int doubleDigitValue(int digit)
{
    int doubledDigit = digit * 2;
    if (doubledDigit >= 10)
        return 1 + doubledDigit % 10;
    else
        return doubledDigit;
}
