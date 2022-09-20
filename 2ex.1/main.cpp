#include <iostream>
using std::cin;
using std::cout;

#define MAX_WIDTH 8
#define HEIGHT 4

void printNChars(char c, int n);
void printNewline();

int main()
{
    for (int i = 0; i < HEIGHT; i++) {
        printNChars(' ', i);
        printNChars('#', MAX_WIDTH - 2 * i);
        printNewline();
    }
    return 0;
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
