#include <iostream>
using std::cout;

typedef char* arrayString;

char characterAt(arrayString s, int index)
{
    return s[index];
}

int length(arrayString s)
{
    int count = 0;
    while (s[count] != '\0') {
        count++;
    }
    return count;
}

void append(arrayString& s, char c)
{
    int oldCount = length(s);

    arrayString newS = new char[oldCount + 2];
    for (int i = 0; i < oldCount; i++) {
        newS[i] = s[i];
    }
    newS[oldCount] = c;
    newS[oldCount + 1] = '\0';

    delete[] s;
    s = newS;
}

void concatenate(arrayString& s1, arrayString s2)
{
    int s1Len = length(s1);
    int s2Len = length(s2);

    arrayString newS = new char[s1Len + s2Len + 1];
    for (int i = 0; i < s1Len; i++) {
        newS[i] = s1[i];
    }
    for (int i = 0; i < s2Len; i++) {
        newS[s1Len + i] = s2[i];
    }
    newS[s1Len + s2Len] = '\0';

    delete[] s1;
    s1 = newS;
}

void testAppend()
{
    arrayString a = new char[5];
    a[0] = 'T'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = '\0';
    append(a, '!');
    cout << a << '\n';
}

void testConcatenate()
{
    arrayString a = new char[6];
    a[0] = 'H'; a[1] = 'e'; a[2] = 'l'; a[3] = 'l'; a[4] = 'o'; a[5] = '\0';
    arrayString b = new char[6];
    b[0] = 'W'; b[1] = 'o'; b[2] = 'r'; b[3] = 'l'; b[4] = 'd'; b[5] = '\0';

    concatenate(a, b);
    cout << a << '\n';
    cout << (void*)a << '\n';
}

int main()
{
    testConcatenate();
    return 0;
}
