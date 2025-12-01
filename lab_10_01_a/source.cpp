#include <iostream>
#include <vector>
#include <Windows.h>
#include <iomanip>

#include "Student.h"
#include "StudProc.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Student> students;
    int menuItem;

    do {
        cout << "\nМЕНЮ \n";
        cout << "[1] Введення даних з клавіатури\n";
        cout << "[2] Вивести прізвище і середній бал\n";
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
                cout << "Список порожній, спочатку введіть дані.\n";
            break;

        case 3:
            if (!students.empty()) {
                double proc = StudentProcessor::CalculatePhysicsPercentage(students);
                cout << "Відсоток студентів з 4 або 5 з фізики: "
                    << fixed << setprecision(2) << proc << "%" << endl;
            }
            else {
                cout << "Список порожній.\n";
            }
            break;

        case 0:
            cout << "До побачення!\n";
            break;

        default:
            cout << "Невірний пункт меню!\n";
        }
    } while (menuItem != 0);

    return 0;
}