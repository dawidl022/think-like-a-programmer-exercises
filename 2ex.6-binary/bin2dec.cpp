#include <iostream>
using std::cin;
using std::cout;


int main()
{
    int number = 0;

    for (char c = cin.get(); c == '0' || c == '1'; c = cin.get()) {
        number <<= 1;
        number += c - '0';
    }

    cout << number << "\n";
    return 0;
}
