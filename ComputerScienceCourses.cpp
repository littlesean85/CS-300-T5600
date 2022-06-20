#include <iostream>
#include <fstream>
#include <vector> 

using namespace std;

struct CsCourse {
	string courseNumber;
	string courseName;
	vector<string> coursePrerequisites;

};

vector<string> tokenize(string c, string del = " ")

{
	vector<string> strArray;
	int begin = 0;
	int end = c.find(del);
	while (end != -1) {
		strArray.push_back(c.substr(begin, end - begin));
		begin = end + del.size();
		end = c.find(del, begin);

	}

	strArray.push_back(c.substr(begin, end - begin));
	return strArray;

}

vector<CsCourse> LoadDataStructure()
{
	ifstream fin("ABCUCourseInput.txt", ios::in);

	vector<CsCourse> courses;

	string line;

	while (1) 
	{
		getline(fin,line);

		if (line == "-1")
			break;

		CsCourse course;

		vector<string> tokenizedInfo = tokenize(line, ",");

		course.courseNumber =tokenizedInfo[0];
		course.courseName =tokenizedInfo[1];

		for (int i = 2; i < tokenizedInfo.size(), i++;){
			course.coursePrerequisites.push_back(tokenizedInfo[i]);

		}

		courses.push_back(course);

	}
	fin.close();

	return courses;

	
}

void printCsCourse(CsCourse course)
{
	string courseNumber = course.courseNumber;
	string courseName = course.courseName;
	vector<string> coursePrerequisites = course.coursePrerequisites;


	cout << "Course Number: " << courseNumber << endl;
	cout << "Course Name: " << courseName << endl;
	cout << "Prerequisites: ";
	for (int i = 0; coursePrerequisites.size(); i++) {
		cout << coursePrerequisites[i] << " " << endl;


	}
	
	cout << endl;

}

void printCsCourseList(vector<CsCourse> courses)
{
	int n = courses.size();

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (courses[j].courseNumber > courses[j + 1].courseNumber) {
				swap(courses[j + 1], courses[j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		
		printCsCourse(courses[i]);
	}
}

void searchCsCourse(vector<CsCourse> courses) {
	int n = courses.size();

	string courseNumber;
	int f = 0;

	cout << "Enter Course Number: ";
	cin >> courseNumber;

	for (int i = 0; i < n; i++) {

		if (courses[i].courseNumber == courseNumber) {
			f = 1;

			printCsCourse(courses[i]);
			break;

		}

	}

	if (f == 0) {
		cout << "No course number found" << endl;
	}

}

int main(int argc, char** argv)
{
	vector<CsCourse> courses;

	cout << "1. Load Data Structure." << endl;
	cout << "2. Print Course List." << endl;
	cout << "3. Print Course." << endl;
	cout << "9. Exit" << endl;

	int cs;

	do {
		cout << "Enter Menu Option: ";
		cin >> cs;

		switch (cs)
		{
		case 1: courses = LoadDataStructure();
			break;

		case 2: printCsCourseList(courses);
			break;

		case 3: searchCsCourse;
			break;

		case 9: cout << "Thank you for using the course planner!" << endl;
			break;

		default: cout << cs << " is not a valid option." << endl;
			break;
		}
		
		}

		while (cs != 9);

		return 0;
	}

	



