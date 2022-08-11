#pragma once
#include <string>
#include "Degree.h"

class Student {

//Requirement (D1 & D2c)
//All variables are private and must be assessed via public methods.
private:
	std::string studentId;
	std::string firstName;
	std::string lastName;
	std::string email;
	int age;
	int daysToComplete[3];
	DegreeProgram studentDegree;

public:
	//Requirement (D2d)
	//Constructor - defines default parameters & initializes
	Student(
		std::string idVal = "A0",
		std::string firstVal = "First",
		std::string lastVal = "Last",
		std::string emailVal = "No Email",
		int ageVal = 0,
		int days1 = 0,
		int days2 = 0,
		int days3 = 0,
		DegreeProgram degreeVal = NA
	);

	//Copy constructor
	Student(const Student& source);

	//Destructor
	~Student();

	//Method prototypes ~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	//Requirements (D2a & D2b) - Getters and setters.
	//Get & set id
	const std::string get_id();
	void set_id(std::string idVal);

	//Get & set first name
	const std::string get_firstName();
	void set_firstName(std::string firstVal);

	//Get & set last name
	const std::string get_lastName();
	void set_lastName(std::string lastVal);

	//Get & set email
	const std::string get_email();
	void set_email(std::string emailVal);

	//Get & set age
	const int get_age();
	void set_age(int ageVal);

	//Get & set days to complete
	int get_daysToComplete(int course);
	void set_daysToComplete(int course, int daysVal);

	//Get & set degree program
	const std::string get_degreeProgram();
	void set_degreeProgram(std::string degreeVal);

	//Requirement (D2e) - print() method.
	//Display student info
	const void print();

	
};

