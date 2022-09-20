#include <iostream>
using std::cin;
using std::cout;

#define HEIGHT 4
#define MAX_WIDTH HEIGHT * 4 - 4

void printBoat(int i);

int main()
{
    for (int i = 0; i < HEIGHT; i++) {
        printBoat(i);
    }
    for (int i = HEIGHT - 1; i >= 0; i--) {
        printBoat(i);
    }

    return 0;
}

void printNChars(char c, int n);
void printNewline();

void printBoat(int i)
{
    printNChars(' ', i);
    printNChars('#', i + 1);
    printNChars(' ', MAX_WIDTH - 4 * i);
    printNChars('#', i + 1);
    printNewline();
}

void printNChars(char c, int n)
{
    for (int i = 0; i < n; i++) {
        cout << c;
    }
}

void printNewline()
{
    cout << "\n";
}
