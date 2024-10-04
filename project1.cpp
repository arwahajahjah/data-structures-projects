#include<iostream>
#include<string>
using namespace std;
const int size = 4;
struct date {
	int day;
	int month;
	int year;
};
struct student {
	int ID;
	string name;
	double gpa;
	date DOB;
	bool ap;
	char grade[4];
};
void read(student  student[]) {
	student[0] = { 998542, "Ahmad", 3.8, {19, 5, 2002}, 0, {'A', 'C', 'F', 'D'} };
	student[1] = { 986521, "Sara", 3.5, {20, 6, 2002}, 0, {'F', 'B', 'A', 'C'} };
	student[2] = { 995271, "Rami", 2.8, {18, 1, 2003}, 1, {'C', 'F', 'F', 'A'} };
	student[3] = { 987741, "Rania", 4.0, {13, 8, 2003}, 0, {'A', 'A', 'A', 'A'} };
}
void print(student students[], int size) {
	cout << "Names of students:" << endl;
	for (int i = 0; i < size; ++i) {
		cout << students[i].name << endl;
	}
}

void APs(student student[], int size)
{
	for (int i = 0; i < 4; i++)
	{
		if (student[i].ap == 1)
			cout << student[i].name;
	}
}

void Fs(student student[])
{
	int c = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if (student[i].grade[j] == 'F')
				c++;
		cout << student[i].name;
		cout << " " << c;
		cout << endl;
		c = 0;
	}
}
void DOBlarger(student student[], int size) {
	cout << "Students who have DOB larger than 2002:" << endl;
	for (int i = 0; i < size; ++i) {
		if (student[i].DOB.year > 2002) {
			cout << student[i].name << endl;
		}
	}
}
int main() {
	const int size = 4;
	int i = 0;
	student student[size];
	int choice;
	do {
		system("cls");
		cout << "1. Read:\n ";
		cout << "2. Print students names:\n ";
		cout << "3. Number of F each student has:\n ";
		cout << "4. Name of student who has DOB larger than 2002:\n ";
		cout << "5. Exit:\n ";
		cout << "Enter option: ";
		cin >> choice;
		switch (choice) {
		case 1:
			read(student);
			break;
		case 2:
			print(student, size);

			break;
		case 3:
			Fs(student);
			break;
		case 4:DOBlarger(student, size);
			break;
		case 5:
			cout << "Exiting" << endl;
			break;
		default: cout << "Invalid option\n";
			break;
		}
		system("PAUSE");
	} while (choice != 5);

	return 0;
}