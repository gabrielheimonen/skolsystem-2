#include "SchoolSystem.h"
#include <string>
#include <iostream>
#include <string>

void SchoolSystem::Run()
{
	
	while (true)
	{

		PrintMenu();
		std::cin >> input;

		switch (input)
		{
		case 1:
			std::cout << "Skriv namnet på eleven:\n";
			std::cin >> Name;
			std::cout << "Skriv elevens ålder:\n";
			std::cin >> Age;
			AddStudent(Name, Age);
			break;

		case 2: 
			std::cout << "Vad heter eleven du vill ta bort ifrån systemet??\n";
			std::cin >> studentName;
			RemoveStudent(studentName);
			break;

		case 3:
			CheckStudent();
			break;

		case 5:
			CheckklassInfo();
			break;

		
		case 6:
			AddStudentToklass();
			break;

		case 7:
			std::cin >> className;
			AddSchoolklass(className);
		
			break;
		case 8: 
			RemoveStudentFromklass();
		default:
			break;
		}
		
	}
}

void SchoolSystem::AddStudent(std::string name, int age)
{

	Student student;
	student.name = Name;
	student.age = Age;
	students.push_back(student);
}

void SchoolSystem::CheckStudent() 
{
	std::string StudentNameCheck = "";
	std::cout << "Skriv studentens namn som du vill kolla om den finns i systemet \n";
	std::cin >> StudentNameCheck;

	for (auto i : students)
	{
		if (StudentNameCheck == i.name) 
		{
			std::cout << "Elevens finns i systemet \n";
			return;
		}
	}
	std::cout << "Eleven finns inte i systemet \n";
}

void SchoolSystem::RemoveStudent(std::string name)
{

	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].name == name) {
			students.erase(students.begin() + i);
			std::cout << name + " har tagits bort \n";
		}
	}
}

void SchoolSystem::PrintMenu() 
{
	std::cout << "Hej och välkommen till skol systemet vill du antingen \n";
	std::cout << "1. Lägga till en elev \n";
	std::cout << "2. Ta bort en elev ifrån en klass \n";
	std::cout << "3. Kolla om en elev redan finns i systemet \n";
	std::cout << "4. Ta bort en elev ifrån hela systemet \n";
	std::cout << "5. Kolla information om en hel klass \n";
	std::cout << "6. Lägga till en elev som redan finns i systemet i en existerande klass \n";
	std::cout << "7. Lägg till en skol klass \n";
	std::cout << "8. Ta bort en elev ifrån en klass";
	std::cout << "\n";
}

void SchoolSystem::AddStudentToklass()
{
	std::string StudentName;
	std::string SchoolClass;


	std::cout << "Vilken elev vill du lägga in i en klass? \n";
	std::cin >> StudentName;
	std::cout << "vilke klass vill du lägga till elevn i? \n";
	std::cin >> SchoolClass;

	for (auto& klasses : schoolClasses)
	{
		if (klasses != SchoolClass)
			std::cout << "Denna elev eller klass finns inte \n";
	}

	for (auto& student : students)
	{
		if (student.name == StudentName)
		{
			student.klass = SchoolClass;
			std::cout << "Klassen och eleven finns i nu i klassen \n";
		}
	}
}

void SchoolSystem::AddSchoolklass(std::string klass) 
{
	schoolClasses.push_back(klass);
}

void SchoolSystem::CheckklassInfo()
{
	std::cout << "vilken klass vill du kolla upp?";
	std::cin >> classInfoInput;
	std::cout << "dessa elever finns i klassen: \n";
	for(size_t i = 0; i < students.size(); i++)
	{
		if (classInfoInput == students[i].klass) 
		{
			std::cout << students[i].name << "\n";
		}
		else if(classInfoInput != students[i].klass)
		{
			std::cout << "Klassen finns inte! \n";
		}
	}
}


void SchoolSystem::RemoveStudentFromklass()
{
	std::string deletStudent = "";
	std::cout << "Vad heter eleven? \n";
	std::cin >> deletStudent;

	for (size_t i = 0; i < students.size(); i++) 
	{
		if (students[i].name == deletStudent)
		{
			students[i].klass = "";
			return;
		}
	}
}
