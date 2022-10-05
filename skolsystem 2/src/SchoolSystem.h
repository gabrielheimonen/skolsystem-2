#pragma once
#include "Student.h"
#include <vector>
#include <iostream>

class SchoolSystem
{
public:
	void Run();

	int input = 0;
	std::string Name = "";
	int Age = 0;
	std::string studentName = "";
	std::string className = "";
	std::string classInfoInput = "";


	void AddStudent(std::string name, int age);
	void RemoveStudent(std::string name);
	void PrintMenu();
	void AddStudentToklass();
	void CheckStudent();
	void AddSchoolklass(std::string klass);
	void CheckklassInfo();
	void RemoveStudentFromklass();

	
	std::vector<Student> students;
	std::vector<std::string> schoolClasses;
};
