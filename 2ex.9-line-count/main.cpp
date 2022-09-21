#include <iostream>
using std::cout;
using std::cin;

struct WordStats {
    int len;
    int vowelCount;
    bool endOfLine;
};

WordStats parseWord();

int main()
{
    int maxLen = 0;
    int maxVowelCount = 0;
    int wordCount = 0;
    WordStats stats = parseWord();

    do {
        if (stats.len > 0) {
            wordCount++;
            if (stats.len > maxLen) {
                maxLen = stats.len;
            }
            if (stats.vowelCount > maxVowelCount) {
                maxVowelCount = stats.vowelCount;
            }
        }
        if (!stats.endOfLine) {
            stats = parseWord();
        }
    } while (!stats.endOfLine);

    cout << "Total number of words is " << wordCount << '\n';
    cout << "Longest word has length " << maxLen << '\n';
    cout << "The highest number of vowels (excluding y) in a single word is "
        << maxVowelCount << '\n';

    return 0;
}

bool isWordChar(char c);

WordStats parseWord()
{
    int len = 0;
    int vowelCount = 0;
    char c;

    for (c = cin.get(); isWordChar(c); c = cin.get()) {
        len++;

        c |= 32;
        switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            vowelCount++;
        }
    }

    return { len, vowelCount, c == '\n' };
}

bool isWordChar(char c)
{
    if (c == '\'') {
        return true;
    }
    c |= 32;
    return c >= 'a' && c <= 'z';
}
