#include "pch.h"
#include "CppUnitTest.h"
#include "F:\Project\lab_10_01_a\student.h"   
#include "F:\Project\lab_10_01_a\StudProc.h"
#include "F:\Project\lab_10_01_a\StudentProcessor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace LB101AUnitTest
{
	TEST_CLASS(LB101AUnitTest)
	{
	public:

		TEST_METHOD(TestCalculatePhysicsPercentage_Mixed)
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

			Student s4;
			s4.physics = 2; 
			students.push_back(s4);

			double result = StudentProcessor::CalculatePhysicsPercentage(students);

	
			Assert::AreEqual(50.0, result, 0.001);
		}

		TEST_METHOD(TestCalculatePhysicsPercentage_AllGood)
		{
			vector<Student> students;
			Student s1; s1.physics = 5; students.push_back(s1);
			Student s2; s2.physics = 5; students.push_back(s2);

			double result = StudentProcessor::CalculatePhysicsPercentage(students);

			Assert::AreEqual(100.0, result, 0.001);
		}

		TEST_METHOD(TestCalculatePhysicsPercentage_AllBad)
		{
			vector<Student> students;
			Student s1; s1.physics = 3; students.push_back(s1);
			Student s2; s2.physics = 2; students.push_back(s2);

			double result = StudentProcessor::CalculatePhysicsPercentage(students);

			Assert::AreEqual(0.0, result, 0.001);
		}

		TEST_METHOD(TestCalculatePhysicsPercentage_Empty)
		{
			vector<Student> students;
			double result = StudentProcessor::CalculatePhysicsPercentage(students);
			Assert::AreEqual(0.0, result, 0.001);
		}
	};
}