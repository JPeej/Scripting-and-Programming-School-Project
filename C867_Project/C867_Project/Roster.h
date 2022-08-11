#pragma once
#include <string>
#include "Student.h"

class Roster {
private:
	const int NUM_COURSES = 3;
	const int NUM_STUDENTS = 5;
	const char PARSE_DELIMITER = ',';
	
public:
	//Constructor
	Roster();

	//Copy Constructor
	Roster(const Roster& source);

	//Destructor
	~Roster();

	//Member
	//Requirement (E1)
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

	//Method prototypes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//Requirement(E2a & E2b)
	//Parse provided student info and adds student to classRosterArray
	void parseInfo(const std::string data[]);

	//Requirement(E2b & E3a)
	//Add a new student object.  Added variable [index] to insert the student into the correct classRosterArray index.
	void add(int index, std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

	//Requirement(E3b)
	//Remove student object from roster via id. If not found -> error.
	void remove(std::string studentID);

	//Requirement(E3c)
	//Display all student information within classRosterArry.
	void printAll();

	//Requirement(E3d)
	//Calculate and display average days in course for given student.
	void printAverageDaysInCourse(std::string studentID);

	//Requirement(E3e)
	//Displays all invalid email addresses.
	void printInvalidEmails();

	//Requirement(E3f)
	//Display all students in given degree.
	void printByDegreeProgram(DegreeProgram degreeProgram);
};

