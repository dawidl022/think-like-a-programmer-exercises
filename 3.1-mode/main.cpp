#include <iostream>
using std::cout;

int modeOfSurvey(int len, int answers[]);

int main()
{
    int answers[20] = { 8, 8, 5, 1, 3, 6, 4, 10, 10, 5, 7, 10, 8, 6, 7, 7, 10, 2, 9, 6 };
    cout << modeOfSurvey(20, answers) << '\n';

    return 0;
}

#define MAX_ANSWER 10

int modeOfSurvey(int len, int answers[])
{
    int results[MAX_ANSWER + 1] = { 0 };
    for (int i = 0; i < len; i++) {
        results[answers[i]]++;
    }

    int mode = 1;
    int modeOccurrences = results[1];

    for (int i = 2; i < MAX_ANSWER + 1; i++) {
        if (results[i] > modeOccurrences) {
            mode = i;
            modeOccurrences = results[i];
        }
    }
    return mode;
}
