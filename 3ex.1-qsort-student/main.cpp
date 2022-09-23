#include <iostream>
#include <cstdio>
#include <string>
using std::cout;
using std::string;

struct student {
    int grade;
    int studentID;
    string name;
};

int compareStudent(const void* student1, const void* student2);

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

    qsort(students, STUDENT_COUNT, sizeof(student), compareStudent);

    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Grade: %3d, ID: %3d, Name: ", students[i].grade,
            students[i].studentID);
        cout << students[i].name << '\n';
    }

    return 0;
}

int compareStudent(const void* student1, const void* student2)
{
    student* s1 = (student*)student1;
    student* s2 = (student*)student2;

    int gradeDiff = s1->grade - s2->grade;
    if (gradeDiff != 0) {
        return gradeDiff;
    }
    return s1->studentID - s2->studentID;
}
