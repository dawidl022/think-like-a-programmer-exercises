#include <iostream>
using std::cout;

struct studentNode {
    int id;
    int grade;
    studentNode* next;
};

void addRecord(studentNode*& head, int id, int grade)
{
    studentNode* newHead = new studentNode;

    newHead->id = id;
    newHead->grade = grade;
    newHead->next = head;

    head = newHead;
}

double averageRecord(studentNode* head)
{
    if (head == nullptr) return 0;

    double total = 0;
    int count = 0;

    for (; head != nullptr; head = head->next) {
        total += head->grade;
        count++;
    }
    return total / count;
}

void printRecord(studentNode* head)
{
    cout << "[HEAD] -> ";

    for (; head != nullptr; head = head->next) {
        cout << "[id: " << head->id << " grade: " << head->grade << "] -> ";
    }

    cout << "NULL\n";
}

void deleteCollection(studentNode*& head)
{
    if (head == nullptr) return;

    deleteCollection(head->next);

    delete head;
    head = nullptr;
}

int main()
{
    studentNode* students = nullptr;
    printRecord(students);
    cout << averageRecord(students) << '\n';

    addRecord(students, 1, 81);
    printRecord(students);

    addRecord(students, 2, 76);
    printRecord(students);

    cout << averageRecord(students) << '\n';

    deleteCollection(students);
    printRecord(students);

    return 0;
}
