#include<iostream>
using namespace std;

const int size = 4;

struct date {
    int day;
    int month;
    int year;
};

struct student {
    int id;
    string name;
    double gpa;
    date dayofbirth;
    bool academicprobation;
    char grade[4];
};

void read(student students[]) {
    students[0] = { 998542, "Ahmad", 3.8, {19, 5, 2002}, 0, {'A', 'C', 'F', 'D'} };
    students[1] = { 986521, "Sara", 3.5, {20, 6, 2002}, 0, {'F', 'B', 'A', 'C'} };
    students[2] = { 995271, "Rami", 2.8, {18, 1, 2003}, 1, {'C', 'F', 'F', 'A'} };
    students[3] = { 987741, "Rania", 4.0, {13, 8, 2003}, 0, {'A', 'A', 'A', 'A'} };
}

void print(student students[], int size) {
    cout << "Names of students:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << students[i].name << endl;
    }
}

void countFgrades(student students[]) {
    int c = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (students[i].grade[j] == 'F') {
                c++;
            }
        }
        cout << students[i].name << " " << c << endl;
        c = 0;
    }
}

void checklarger(student students[], int size) {
    cout << "Students who have day of birth later than 2002:" << endl;
    for (int i = 0; i < size; ++i) {
        if (students[i].dayofbirth.year > 2002) {
            cout << students[i].name << endl;
        }
    }
}

int main() {
    const int size = 4;
    student students[size];
    int choice;

    do {
        system("cls");
        cout << "1. Read:\n";
        cout << "2. Print students names:\n";
        cout << "3. Number of F each student has:\n";
        cout << "4. Name of student who has DOB larger than 2002:\n";
        cout << "5. Exit:\n";
        cout << "Enter option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            read(students);
            break;
        case 2:
            print(students, size);
            break;
        case 3:
            countFgrades(students);
            break;
        case 4:
            checklarger(students, size);
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
