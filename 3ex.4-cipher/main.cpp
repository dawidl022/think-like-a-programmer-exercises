#include <iostream>
using std::cin;
using std::cout;

bool isAlpha(char c);
char encodeChar(char c, char encodeMap[]);

int main(int argc, char* argv[])
{
    const char encodeMap[26] = {
        'H', 'L', 'X', 'N', 'D', 'F', 'S', 'C', 'T', 'P', 'K', 'E', 'I',
        'W', 'A', 'O', 'G', 'J', 'Y', 'B', 'M', 'R', 'Z', 'Q', 'V', 'U'
    };

    char* cipherMap;

    if (argc == 2 && strcmp(argv[1], "-d") == 0) {
        char decodeMap[26];
        for (int i = 0; i < 26; i++) {
            decodeMap[encodeMap[i] - 'A'] = i + 'A';
        }
        cipherMap = decodeMap;
    }
    else {
        cipherMap = (char*)encodeMap;
    }

    for (char c = cin.get(); c != -1; c = cin.get()) {
        if (isAlpha(c)) {
            c = encodeChar(c, cipherMap);
        }
        cout << c;
    }

    return 0;
}

bool isAlpha(char c)
{
    return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}

char toUpper(char c);

char encodeChar(char c, char encodeMap[])
{
    int isUpper = c & 32;
    char cipher = encodeMap[toUpper(c) - 'A'];

    if (isUpper) {
        cipher |= 32;
    }
    return cipher;
}

char toUpper(char c)
{
    return c & 0b1011111;
}
