#include <iostream>
using std::cout;

double median(int values[], int valueCount);

#define MONTH_COUNT 12

struct agent {
    int monthlySales[MONTH_COUNT];
};

int main()
{
    const int AGENT_COUNT = 3;
    agent agents[AGENT_COUNT] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {-1, -1, -1, 6464, 9957, 4785, 3875, 3838, 4959, -1, -1, -1},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, -1, -1, -1}
    };

    for (int i = 0; i < AGENT_COUNT; i++) {
        cout << median(agents[i].monthlySales, MONTH_COUNT) << '\n';
    }

    return 0;
}

int compareInt(const void* num1, const void* num2);

double median(int values[], int valueCount)
{
    int vCopy[valueCount];
    for (int i = 0; i < valueCount; i++) vCopy[i] = values[i];

    qsort(vCopy, valueCount, sizeof(int), compareInt);

    // change starts here
    int offset = 0;
    while (offset < valueCount && vCopy[offset] == -1) offset++;

    int realCount = (valueCount - offset);
    int mid = (valueCount - offset) / 2 + offset;

    if (realCount % 2 == 0) {
        int mid2 = mid - 1;
        return (vCopy[mid] + vCopy[mid2]) / 2.0;
    }
    // change ends here
    return vCopy[mid];
}

int compareInt(const void* num1, const void* num2)
{
    int n1 = *(int*)num1;
    int n2 = *(int*)num2;
    return n1 - n2;
}
