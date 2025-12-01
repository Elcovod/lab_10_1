#pragma once
#include <string>
#include "Speciality.h"

struct Student {
    std::string surname;
    int course;
    Speciality specialization;
    int physics;
    int math;
    int prog;
};