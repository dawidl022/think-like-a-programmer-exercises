#include <iostream>
using std::cin;
using std::cout;

#define MAX_WIDTH 8
#define HEIGHT 4

void printCone(int i);

int main()
{
    for (int i = HEIGHT - 1; i >= 0; i--) {
        printCone(i);
    }
    for (int i = 0; i < HEIGHT; i++) {
        printCone(i);
    }
    return 0;
}

void printNChars(char c, int n);
void printNewline();

void printCone(int i)
{
    printNChars(' ', i);
    printNChars('#', MAX_WIDTH - 2 * i);
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
