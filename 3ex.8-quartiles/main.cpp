#include <cstdlib>
#include <iostream>
#include <string>
using std::string;
using std::cout;

struct student {
    int grade;
    int studentID;
    string name;
};

struct quartiles {
    int lower;
    int median;
    int upper;
};

quartiles determineQuartileGrades(student students[], int studentsLen);

int main()
{
    const int STUDENT_COUNT = 10;
    student students[STUDENT_COUNT] = {
        {100, 10003, "Alistair"},
        {68, 10010, "Veronica"},
        {70, 10008, "Candy"},
        {75, 10007, "Leslie"},
        {75, 10004, "Sasha"},
        {87, 10001, "Fred"},
        {81, 10009, "Aretha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {28, 10002, "Tom"},
    };

    quartiles quartiles = determineQuartileGrades(students, STUDENT_COUNT);

    cout << "25% (lower)  quartile grade: " << quartiles.lower << '\n';
    cout << "50% (median) quartile grade: " << quartiles.median << '\n';
    cout << "75% (upper)  quartile grade: " << quartiles.upper << '\n';
}

int compareStudent(const void* student1, const void* student2);

quartiles determineQuartileGrades(student students[], int studentsLen)
{
    student studentsCopy[studentsLen];
    for (int i = 0; i < studentsLen; i++) studentsCopy[i] = students[i];

    qsort(studentsCopy, studentsLen, sizeof(student), compareStudent);

    int mid = (studentsLen - 1) / 2;
    int quart = (mid - 1) / 2;
    int three_quart = (mid + studentsLen) / 2;
    return {
        studentsCopy[quart].grade,
        studentsCopy[mid].grade,
        studentsCopy[three_quart].grade
    };
}


int compareStudent(const void* student1, const void* student2)
{
    student* s1 = (student*)student1;
    student* s2 = (student*)student2;

    return s1->grade - s2->grade;
}
