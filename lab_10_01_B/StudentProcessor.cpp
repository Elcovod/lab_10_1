#include "StudentProcessor.h"
#include <iostream>
#include <iomanip>
#include <string>

namespace StudentProcessor {
	void AddStudents(std::vector<Student>& students) {
		int k;
		std::cout << "Введіть кількість студентів: "; std::cin >> k;

		if (k <= 0) return;

		for (int i = 0; i < k; i++) {
			Student newStudent;
		std::cout << "Студент №" << (students.size() + 1) << ":\n";
		std::cin.ignore();
		std::cout << "Прізвище: ";
		std::getline(std::cin, newStudent.surname);

		std::cout << "Курс: ";
		std::cin >> newStudent.course;

		std::cout << "Спеціальність (0 - КН, 1 - Інф, 2 - МатЕк, 3 - ФізІнф, 4 - Труд): ";
		int specInput;
		std::cin >> specInput;
		newStudent.speciality = static_cast<Speciality>(specInput);

		std::cout << "Оцінка з фізики: ";
		std::cin >> newStudent.physics;

		std::cout << "Оцінка з математики: ";
		std::cin >> newStudent.math;

		switch (newStudent.speciality) {
		case COMPUTER_SCIENCE:
			std::cout << "Оцінка з програмування: ";
			std::cin >> newStudent.programming;
			break;
		case INFORMATICS:
			std::cout << "Введіть оцінку з чисельних методів: ";
			std::cin >> newStudent.num_methods;
			break;
		default:
			std::cout << "Введіть оцінку з педагогіки: ";
			std::cin >> newStudent.pedagogy;
			break;
		}
		students.push_back(newStudent);
		}
	}
	
	void PrintAverage(const std::vector<Student>& students) {
		std::cout << "============================================================\n";
		std::cout << "| " << std::setw(15) << std::left << "Прізвище"
			<< " | " << std::setw(25) << "Спеціальність"
			<< " | " << std::setw(10) << std::right << "Сер. бал" << " |\n";
		std::cout << "------------------------------------------------------------\n";

		for (const auto& s : students) {
			int third_grade_val;
			switch (s.speciality) {
			case COMPUTER_SCIENCE: third_grade_val = s.programming; break;
			case INFORMATICS: third_grade_val = s.num_methods; break;
			default: third_grade_val = s.pedagogy; break;
			}
			double avg = (s.physics + s.math + third_grade_val) / 3.0;

			std::cout << "| " << std::setw(15) << std::left << s.surname
				<< " | " << std::setw(25) << SpecialityNames[s.speciality]
				<< " | " << std::setw(10) << std::right << std::fixed << std::setprecision(2) << avg << " |\n";
		}
		std::cout << "============================================================\n";
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