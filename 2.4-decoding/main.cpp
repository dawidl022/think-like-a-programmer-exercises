#include <iostream>
using std::cin;
using std::cout;

enum Mode {
    uppercase,
    lowercase,
    symbol,
};

void processBuffer(int* buf, int* currMode);

int main()
{
    int buf = 0;
    int currMode = Mode::uppercase;

    for (char c = cin.get(); c != '\n'; c = cin.get()) {
        if (c == ',') {
            processBuffer(&buf, &currMode);
        }
        else {
            buf *= 10;
            buf += c - '0';
        }
    }
    processBuffer(&buf, &currMode);
    cout << '\n';

    return 0;
}

char getChar(int buf, Mode mode);
void outputChar(char c, Mode mode);

void processBuffer(int* buf, int* currMode)
{
    char decoded = getChar(*buf, Mode(*currMode));
    if (decoded == 0) {
        *currMode = (*currMode + 1) % 3;
    }
    else {
        outputChar(decoded, Mode(*currMode));
    }
    *buf = 0;
}


char getChar(int buf, Mode mode)
{
    switch (mode) {
    case Mode::uppercase:
    case Mode::lowercase:
        return buf % 27;

    case Mode::symbol:
        return buf % 9;
    }
}

char getSymbol(char c);

void outputChar(char c, Mode mode)
{
    char symbol;

    switch (mode) {
    case Mode::uppercase:
        symbol = c + 'A' - 1;
        break;

    case Mode::lowercase:
        symbol = c + 'a' - 1;
        break;

    case Mode::symbol:
        symbol = getSymbol(c);
        break;
    }

    cout << symbol;
}

char getSymbol(char c)
{
    const char symbols[] = { '!', '?', ',', '.', ' ', ';', '"', '\'' };
    return symbols[c - 1];
}
