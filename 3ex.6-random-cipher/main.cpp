#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;

void genCipherMap(char map[26]);
bool isAlpha(char c);
char encodeChar(char c, char encodeMap[]);

int main(int argc, char* argv[])
{
    char encodeMap[26];
    genCipherMap(encodeMap);

    for (char c = 'A'; c <= 'Z'; c++) {
        cout << c;
    }
    cout << '\n';

    for (int i = 0; i < 26; i++) {
        cout << encodeMap[i];
    }
    cout << '\n';

    for (char c = cin.get(); c != -1; c = cin.get()) {
        if (isAlpha(c)) {
            c = encodeChar(c, encodeMap);
        }
        cout << c;
    }

    return 0;
}

void genCipherMap(char map[26])
{
    do {
        bool allocated[26] = { false };

        for (int i = 0; i < 26; i++) {
            char c;
            do {
                c = arc4random() % 26;
            } while (allocated[c] || (i < 25 && i == c));
            map[i] = c + 'A';
            allocated[c] = 1;
        }
    } while (map[25] == 'Z');
}

// bool isSameAsPlainText(int i, int c, int target);

// alternative method of generating cipherMap,
// seemed to have no performance gains over the naive approach above
// void genCipherMap(char map[26])
// {
//     do {
//         int unallocated[26];
//         for (int i = 0; i < 26; i++) unallocated[i] = 1;

//         for (int i = 0; i < 26; i++) {
//             int c = arc4random() % (26 - i) + 1;
//             int target = 0;

//             for (int j = 0; j < c || isSameAsPlainText(i, c, target);) {
//                 j += unallocated[target];
//                 if (j < c || isSameAsPlainText(i, c, target)) {
//                     target++;
//                 }
//             }
//             map[i] = target + 'A';
//             unallocated[target] = 0;
//         }
//     } while (map[25] == 'Z');
// }

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

// bool isSameAsPlainText(int i, int c, int target)
// {
//     return i == c && i == target;
// }
