#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int number;
    cin >> number;

    if (number == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int i = 1;
    for (; i <= number; i <<= 1) {}

    i >>= 1;

    for (; i > 0; i >>= 1) {
        if (number >= i) {
            cout << 1;
            number -= i;
        }
        else {
            cout << 0;
        }
    }

    cout << '\n';

    return 0;
}
