#include<iostream>
using namespace std;

const int SIZE = 4;

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    int id;
    string name;
    double gpa;
    Date dayOfBirth;
    bool academicProbation;
    char grades[4];
};

void readStudentsData(Student studentsArray[]) {
    studentsArray[0] = { 998542, "Ahmad", 3.8, {19, 5, 2002}, 0, {'A', 'C', 'F', 'D'} };
    studentsArray[1] = { 986521, "Sara", 3.5, {20, 6, 2002}, 0, {'F', 'B', 'A', 'C'} };
    studentsArray[2] = { 995271, "Rami", 2.8, {18, 1, 2003}, 1, {'C', 'F', 'F', 'A'} };
    studentsArray[3] = { 987741, "Rania", 4.0, {13, 8, 2003}, 0, {'A', 'A', 'A', 'A'} };
}

void printStudentName(Student studentsArray[], int SIZE) {
    cout << "Names of students:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << studentsArray[i].name << endl;
    }
}

void countFailedGrades(Student studentsArray[]) {
    int counter = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (studentsArray[i].grades[j] == 'F') {
                counter++;
            }
        }
        cout << studentsArray[i].name << " " << counter << endl;
        counter = 0;
    }
}

void checkAfter2002(Student studentsArray[], int Size) {
    cout << "Students who have day of birth after 2002:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        if (studentsArray[i].dayOfBirth.year > 2002) {
            cout << studentsArray[i].name << endl;
        }
    }
}

int main() {
    Student studentsArray[SIZE];
    int choice;

    do {
        system("cls");
        cout << "1. Read:\n";
        cout << "2. Print students names:\n";
        cout << "3. Number of F each student has:\n";
        cout << "4. Name of student who has day of birth After 2002:\n";
        cout << "5. Exit:\n";
        cout << "Enter option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            readStudentsData(studentsArray);
            break;
        case 2:
            printStudentName(studentsArray, SIZE);
            break;
        case 3:
            countFailedGrades(studentsArray);
            break;
        case 4:
            checkAfter2002(studentsArray, SIZE);
            break;
        case 5:
            cout << "Exiting" << endl;
            break;
        default:
            cout << "Invalid option\n";
            break;
        }
        system("PAUSE");
    } while (choice != 5);

    return 0;
}