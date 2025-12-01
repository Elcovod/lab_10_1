#include "StudProc.h"
#include <iostream>
#include <iomanip>

namespace StudentProcessor {

    void AddStudents(std::vector<Student>& students) {
        int k;
        std::cout << "Введіть кількість нових студентів: "; std::cin >> k;

        if (k <= 0) return;

        for (int i = 0; i < k; i++) {
            Student newStudent;
            std::cout << "\nСтудент №" << (students.size() + 1) << ":\n";

            std::cin.ignore();
            std::cout << "Прізвище: ";
            std::getline(std::cin, newStudent.surname);

            std::cout << "Курс: ";
            std::cin >> newStudent.course;

            int specInput;
            std::cout << "Спеціальність (0 - F6, 1 - G5, 2 - F7, 3 - G22): ";
            std::cin >> specInput;
            newStudent.specialization = static_cast<Speciality>(specInput);

            std::cout << "Оцінка з фізики: ";
            std::cin >> newStudent.physics;

            std::cout << "Оцінка з математики: ";
            std::cin >> newStudent.math;

            std::cout << "Оцінка з програмування: ";
            std::cin >> newStudent.prog;

            students.push_back(newStudent);
        }
    }

    void PrintAverage(const std::vector<Student>& students) {
        std::cout << "=====================================\n";
        std::cout << "| " << std::setw(18) << std::left << "Прізвище"
            << " | " << std::setw(12) << std::right << "Середній бал" << " |\n";
        std::cout << "-------------------------------------\n";

        for (const auto& student : students) {
            double avg = (student.physics + student.math + student.prog) / 3.0;
            std::cout << "| " << std::setw(18) << std::left << student.surname
                << " | " << std::setw(12) << std::right << std::fixed << std::setprecision(2) << avg << " |\n";
        }
        std::cout << "=====================================\n";
    }

    double CalculatePhysicsPercentage(const std::vector<Student>& students) {
        if (students.empty()) return 0.0;

        int count = 0;
        for (const auto& student : students) {
            if (student.physics == 5 || student.physics == 4) {
                count++;
            }
        }
        return 100.0 * count / students.size();
    }
}