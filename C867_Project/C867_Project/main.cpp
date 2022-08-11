#include <iostream>
#include <string>
#include "Roster.h"
#include "Student.h"

void spacing() {std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;}

//Requirement F
//Create a main function in main.cpp
int main() {

	//Requirement (A)
	//Modify the “studentData Table” to include your personal information as the last item.
	const std::string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
	  "A5,Joshua,Perry,jper856@wgu.edu,28,14,30,30,SOFTWARE" };

	//Requirement F1
	//Print my information.
	std::cout << "C867: Scripting and Programming" << "\nC++" << "\n007217228" << "\nJoshua Perry" << std::endl;
	spacing();

	//Requirement F2
	Roster rosterClass;
	spacing();

	//Requirement F3
	rosterClass.parseInfo(studentData);
	spacing();

	//Requirement F4
	rosterClass.printAll();
	spacing();
	rosterClass.printInvalidEmails();
	spacing();
	for (Student* student : rosterClass.classRosterArray) {
		std::string studId = student->get_id();
		rosterClass.printAverageDaysInCourse(studId);
	}
	spacing();
	rosterClass.printByDegreeProgram(SOFTWARE);
	spacing();
	rosterClass.remove("A3");
	spacing();
	rosterClass.printAll();
	spacing();
	rosterClass.remove("A3");
	spacing();

	return 0;
}