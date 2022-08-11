#include <iostream>
#include <string>
#include "Student.h"
#include "Degree.h"

//Requirement (D2d)
//Constructor - defines default parameters & initializes
Student::Student(std::string idVal,
				 std::string firstVal,
				 std::string lastVal,
				 std::string emailVal,
				 int ageVal, 
				 int days1, 
				 int days2, 
				 int days3, 
				 DegreeProgram degreeVal)

				:studentId{idVal}, 
				 firstName{firstVal}, 
				 lastName{lastVal}, 
				 email{emailVal}, 
				 age{ageVal}, 
				 daysToComplete{days1, days2, days3}, 
				 studentDegree{degreeVal} {
	if (firstName != "First") {
		std::cout << firstName << " " << lastName << " added to system." << std::endl;
	}
	else {
		std::cout << "Default placeholder added." << std::endl;
	}
}

//Copy constructor
Student::Student(const Student& source)
	:Student{ source.studentId, 
			  source.firstName, 
			  source.lastName, 
			  source.email, 
			  source.age, 
			  source.daysToComplete[0], 
			  source.daysToComplete[1], 
			  source.daysToComplete[2], 
			  source.studentDegree} {
	std::cout << "Copy constructor used for : " << source.firstName << " " << source.lastName << std::endl;
}

//Destructor
Student::~Student() {
	std::cout << "Destructor used on : " << firstName << " " << lastName << std::endl;
}

//Methods~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Requirements (D2a & D2b)
//Getters & setters
//Get & set id
const std::string Student::get_id() {
	return studentId;
}
void Student::set_id(std::string idVal) {
	studentId = idVal;
}

//Get & set first name
const std::string Student::get_firstName() {
	return firstName;
}
void Student::set_firstName(std::string firstVal) {
	firstName = firstVal;
}

//Get & set last name
const std::string Student::get_lastName() {
	return lastName;
}
void Student::set_lastName(std::string lastVal) {
	lastName = lastVal;
}

//Get & set email
const std::string Student::get_email() {
	return email;
}
void Student::set_email(std::string emailVal) {
	email = emailVal;
}

//Get & set age
const int Student::get_age() {
	return age;
}
void Student::set_age(int ageVal) {
	age = ageVal;
}

//Get & set days to complete
int Student::get_daysToComplete(int course) {
	return daysToComplete[course];
}
void Student::set_daysToComplete(int course, int daysVal) {
	daysToComplete[course] = daysVal;
}

//Get & set degree program
const std::string Student::get_degreeProgram() {
	std::string degree;
	switch (studentDegree) {
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
	return degree;
}

void Student::set_degreeProgram(std::string degreeVal) {
	if (degreeVal == "SECURITY") {
		studentDegree = SECURITY;
	}
	else if (degreeVal == "NETWORK") {
		studentDegree = NETWORK;
	}
	else if (degreeVal == "SOFTWARE") {
		studentDegree = SOFTWARE;
	}
	else {
		studentDegree = NA;
	}
}

//Requirement (D2e)
//Print function to display student info
const void Student::print() {
	std::cout << "Student ID : " << get_id() << "\t|"
		"First name : " << get_firstName() << "\t|"
		"Last name : " << get_lastName() << "\t|"
		"Email : " << get_email() << "\t|"
		"Age : " << get_age() << "\t|"
		"Days to complete courses 1 : " << get_daysToComplete(0) << "\t|"
		"Days to complete courses 2 : " << get_daysToComplete(1) << "\t|"
		"Days to complete courses 3 : " << get_daysToComplete(2) << "\t|"
		"Degree program : "				<< get_degreeProgram() << std::endl;

}