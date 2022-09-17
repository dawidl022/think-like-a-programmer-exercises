#include <iostream>
using std::cout;

#define MAX_WIDTH 4

void print_triangles(int i);

int main()
{
    for (int i = 1; i <= MAX_WIDTH; i++)
        print_triangles(i);
    for (int i = MAX_WIDTH - 1; i > 0; i--) {
        print_triangles(i);
    }
    return 0;
}

void print_triangles(int i)
{
    for (int j = 0; j < i; j++) {
        cout << "#";
    }
    cout << "\n";
}
