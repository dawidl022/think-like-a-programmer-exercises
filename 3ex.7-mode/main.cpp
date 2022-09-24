#include <cstdlib>
#include <iostream>
#include "./main.hpp"
using std::cout;

int main()
{
    const int ARRAY_SIZE = 12;
    int surveyData[ARRAY_SIZE] = { 4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10 };

    cout << mode(surveyData, ARRAY_SIZE) << '\n';

    return 0;
}

int mode(int nums[], int numsLen)
{
    int numsCopy[numsLen];
    for (int i = 0; i < numsLen; i++) numsCopy[i] = nums[i];

    qsort(numsCopy, numsLen, sizeof(int), compareInts);

    int mode = numsCopy[0];
    int modeCount = 1;
    int currentCount = 0;

    for (int i = 0; i < numsLen; i++) {
        currentCount++;

        if (i == numsLen - 1 || numsCopy[i] != numsCopy[i + 1]) {
            if (currentCount > modeCount) {
                modeCount = currentCount;
                mode = numsCopy[i];
            }
            currentCount = 0;
        }
    }
    return mode;
}

int compareInts(const void* num1, const void* num2)
{
    return *(int*)num1 - *(int*)num2;
}
