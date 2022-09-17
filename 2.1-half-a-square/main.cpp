#include <iostream>
using std::cout;

#define SQUARE_SIZE 5

int main()
{
    for (int i = 0; i < SQUARE_SIZE; i++) {
        for (int j = 0; j < SQUARE_SIZE - i; j++) {
            cout << "#";
        }
        cout << "\n";
    }

    return 0;
}
