#pragma once
#include <string>
#include "Speciality.h"

struct Student {
	std::string surname;
	int course;
	Speciality speciality;
	int physics;
	int math;

	union {
		int programming;    
		int num_methods;  
		int pedagogy;      

	};
};