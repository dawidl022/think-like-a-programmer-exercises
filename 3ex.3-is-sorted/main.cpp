#include <iostream>
using std::cout;

bool isSorted(int a[], int len)
{
    for (int i = 1; i < len; i++) {
        if (a[i] < a[i - 1]) return false;
    }

    return true;
}

int main()
{
    int unsorted[20] = { 3, 5, 5, 1, 7, 10, 10, 8, 9, 5, 10, 6, 6, 7, 5, 3, 4, 7, 8, 6 };
    int sorted[20] = { 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 6, 7, 7, 7, 8, 9, 10, 10 };

    cout << isSorted(unsorted, 20) << '\n';
    cout << isSorted(sorted, 20) << '\n';
}
