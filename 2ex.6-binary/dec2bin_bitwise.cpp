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
    int pow = 0;
    for (; i <= number; i <<= 1, pow++) {}

    i >>= 1;
    pow--;

    for (; i > 0; i >>= 1, pow--) {
        cout << ((number & i) >> pow);
    }

    cout << '\n';

    return 0;
}
