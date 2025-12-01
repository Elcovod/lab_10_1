#include <iostream>
#include <iomanip>
#include <Windows.h.>
#include <vector>


#include "StudentProcessor.h"
#include "Speciality.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Student> students;
	int menuItem;

	do {
		cout << "МЕНЮ\n";
		cout << "[1] Введення даних з клавіатури\n";
		cout << "[2] Вивести прізвище, спеціальність і середній бал\n";
		cout << "[3] Відсоток студентів з 4 або 5 з фізики\n";
		cout << "[0] Вийти\n";
		cout << "Введіть значення: ";
		cin >> menuItem;

		switch (menuItem) {
		case 1:
			StudentProcessor::AddStudents(students);
			break;
		case 2:
			if (!students.empty())
				StudentProcessor::PrintAverage(students);
			else
				cout << "Список студентів порожній. Спочатку додайте студентів.\n";
			break;

		case 3:
			if (!students.empty()) {
				double percentage = StudentProcessor::CalculatePhysicsPercentage(students);
				cout << "Відсоток студентів з оцінкою 4 або 5 з фізики: "
					<< fixed << setprecision(2) << percentage << "%\n";

			}
			else {
				cout << "Список студентів порожній. Спочатку додайте студентів.\n";
			}
			break;
		case 0:
			cout << "Вихід з програми.\n";
			break;
		}
	} while (menuItem != 0);
	return 0;
}