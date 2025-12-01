#pragma once
#include <vector>
#include "Student.h"

namespace StudentProcessor {
    void AddStudents(std::vector<Student>& students);
    void PrintAverage(const std::vector<Student>& students);
    double CalculatePhysicsPercentage(const std::vector<Student>& students);
}