#include <iostream>
using std::cout;

#define MAX_WIDTH 4
#define ROW_COUNT 7

int main()
{
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < MAX_WIDTH - abs(MAX_WIDTH - 1 - i); j++) {
            cout << "#";
        }
        cout << "\n";
    }
    return 0;
}
