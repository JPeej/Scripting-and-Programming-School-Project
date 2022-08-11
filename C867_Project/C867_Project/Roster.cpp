#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include "Degree.h"
#include "Roster.h"
#include "Student.h"

//Constructor
Roster::Roster() {
	std::cout << "Roster created." << std::endl;
}

//Copy constructor
Roster::Roster(const Roster& source)
	:Roster{} {
	std::cout << "Copy constructor used for roster." << std::endl;
}

//Destructor
Roster::~Roster() {
	for (int i = 0; i < NUM_STUDENTS; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
	std::cout << "Destructor called used for roster." << std::endl;
}

//Methods ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Requirement (E2a & E2b)
//Parse through data in a given array and use it to create new student objects.
void Roster::parseInfo(const std::string dataArray[]) {
	for (int i = 0; i < NUM_STUDENTS; ++i) {

		//Select indivdual string to parse, set stringstream to said string, and create vector to hold parsed variables.
		std::string dataToParse = dataArray[i];
		std::stringstream inSS(dataToParse);
		std::vector<std::string> parsedVariables;
		
		//Parse variables and push them to vector.
		while (inSS.good()) {
			std::string data;
			std::getline(inSS, data, ',');
			parsedVariables.push_back(data);
		}

		//Set variables to parsed values found in vector.
		std::string studentId = parsedVariables[0];
		std::string firstName = parsedVariables[1];
		std::string lastName = parsedVariables[2];
		std::string email = parsedVariables[3];
		int age = std::stoi(parsedVariables[4]);
		int days1 = std::stoi(parsedVariables[5]);
		int days2 = std::stoi(parsedVariables[6]);
		int days3 = std::stoi(parsedVariables[7]);
		std::string degree = parsedVariables[8];
		DegreeProgram degreeEnum;

		//Convert degree string to DegreeProgram enum
		if (degree == "SECURITY") {
			degreeEnum = SECURITY;
		}
		else if (degree == "NETWORK") {
			degreeEnum = NETWORK;
		}
		else if (degree == "SOFTWARE") {
			degreeEnum = SOFTWARE;
		}
		else {
			degreeEnum = NA;
		}

		//Call add function
		add(i, studentId, firstName, lastName, email, age, days1, days2, days3, degreeEnum);
	}
}

//Requirement (E2b & E3a)
//Create new student object and insert into the classRosterArray. Added variable [index] to insert the student into the correct classRosterArray index.
void Roster::add(int index, 
				 std::string studentID, 
				 std::string firstName, 
				 std::string lastName, 
				 std::string emailAddress, 
				 int age, 
				 int daysInCourse1, 
				 int daysInCourse2, 
				 int daysInCourse3, 
				 DegreeProgram degreeprogram) {
	Student* newStudent = new Student{ studentID, 
									   firstName, 
									   lastName, 
									   emailAddress, 
									   age, 
									   daysInCourse1, 
									   daysInCourse2, 
									   daysInCourse3, 
									   degreeprogram };
	classRosterArray[index] = newStudent;
}

//Requirement(E3b)
//Remove student object from roster via id. If not found -> error.
void Roster::remove(std::string studentID) {
	int index = -1;
	bool foundId = false;
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		std::string currentId = (classRosterArray[i]->get_id());
		if (studentID == currentId) {
			index = i;
			foundId = true;
		}
	}
	if (foundId) {
		classRosterArray[index] = nullptr;
		Student* newStudent = new Student{};
		classRosterArray[index] = newStudent;
	}
	else {
		std::cout << "Student ID does not exist." << std::endl;
	}
	
}

//Requirement(E3c)
//Display all student information within classRosterArry.
void Roster::printAll()
{
	for (Student *students : classRosterArray) {
		students->print();
	}
}

//Requirement(E3d)
//Calculate and display average days in course for given student.
void Roster::printAverageDaysInCourse(std::string studentID) {
	int index = -1;
	bool foundId = false;
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		std::string currentId = (classRosterArray[i]->get_id());
		if (studentID == currentId) {
			index = i;
			foundId = true;
		}
	}
	if (foundId) {
		double course1 = (classRosterArray[index]->get_daysToComplete(0));
		double course2 = (classRosterArray[index]->get_daysToComplete(1));
		double course3 = (classRosterArray[index]->get_daysToComplete(2));

		double average = (course1 + course2 + course3) / NUM_COURSES;

		std::cout << classRosterArray[index]->get_firstName() << " has an average of " << average << " days in their courses." << std::endl;
	}
	else {
		std::cout << "Student ID does not exist." << std::endl;
	}
}

//Requirement(E3e)
//Displays all invalid email addresses.
void Roster::printInvalidEmails() {
	for (Student* student : classRosterArray) {
		std::string email;
		email = student->get_email();
		std::size_t foundAt = email.find('@');
		std::size_t foundPeriod = email.find('.');
		std::size_t foundSpace = email.find(' ');
		if (foundAt != std::string::npos) {
			if (foundPeriod != std::string::npos) {
				if (foundSpace == std::string::npos) {
					std::cout << student->get_firstName() << " " << student->get_lastName() << " has entered a correctly formatted email of " << email << "." << std::endl;
				}
				else {
					std::cout << student->get_firstName() << " " << student->get_lastName() << " has entered an incorrectly formatted email containing a space." << std::endl;
				}
			}
			else {
				std::cout << student->get_firstName() << " " << student->get_lastName() << " has entered an incorrectly formatted email not containing a '.' ." << std::endl;
			}
		}
		else {
			std::cout << student->get_firstName() << " " << student->get_lastName() << " has entered an incorrectly formatted email not containing an '@' symbol." << std::endl;
		}
	}
	
}

//Requirement(E3f)
//Displays all students for a given degree
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	std::string degree;
	switch (degreeProgram) {
	case 0:
		degree = "SECURITY";
		break;
	case 1:
		degree = "NETWORK";
		break;
	case 2:
		degree = "SOFTWARE";
		break;
	default:
		degree = "NA";
		break;
	}
	for (Student* student : classRosterArray) {
		if (degree == student->get_degreeProgram()) {
			std::cout << student->get_firstName() << " " << student->get_lastName() << " is in the " << degree << " program." << std::endl;
		}
	}
}
