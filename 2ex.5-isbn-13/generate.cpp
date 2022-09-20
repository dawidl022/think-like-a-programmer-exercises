#include <iostream>
using std::cin;
using std::cout;

#define ISBN_LEN 13


int getIsbn13Checksum();

int main()
{
    cout << getIsbn13Checksum() << "\n";
    return 0;
}

bool isNonDigit(char c);
bool isIndexWeighted3(int i);
int charToInt(char c);

int getIsbn13Checksum()
{
    int sum = 0;
    for (int i = 0; i < ISBN_LEN - 1;) {
        char c = cin.get();

        if (isNonDigit(c)) {
            continue;
        }
        int digit = charToInt(c);

        if (isIndexWeighted3(i)) {
            sum += 3 * digit;
        }
        else {
            sum += digit;
        }

        i++;
    }

    return 10 - sum % 10;
}

bool isNonDigit(char c)
{
    return c < '0' || c > '9';
}

bool isIndexWeighted3(int i)
{
    return i != ISBN_LEN - 1 && i % 2 == 1;
}

int charToInt(char c)
{
    return c - '0';
}
