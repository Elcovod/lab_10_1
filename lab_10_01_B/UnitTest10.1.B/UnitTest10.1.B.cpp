#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <string>


#include "F:\Project\lab_10_01_B\StudentProcessor.cpp"
#include "F:\Project\lab_10_01_B\Speciality.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace LB101BUnitTest
{
	TEST_CLASS(LB101BUnitTest)
	{
	public:

		TEST_METHOD(TestCalculatePhysicsPercentage)
		{
			vector<Student> students;

			Student s1;
			s1.physics = 5;
			students.push_back(s1);

			Student s2;
			s2.physics = 4;
			students.push_back(s2);

			Student s3;
			s3.physics = 3;
			students.push_back(s3);

			double result = StudentProcessor::CalculatePhysicsPercentage(students);

			Assert::AreEqual(66.66, result, 0.01);
		}

		TEST_METHOD(TestUnionWork)
		{
			Student s;
			s.speciality = COMPUTER_SCIENCE;

			s.programming = 100;

			Assert::AreEqual(100, s.programming);

			Assert::AreEqual(100, s.num_methods);
		}

		TEST_METHOD(TestEmptyList)
		{
			vector<Student> emptyList;
			double result = StudentProcessor::CalculatePhysicsPercentage(emptyList);

			Assert::AreEqual(0.0, result, 0.01);
		}
	};
}