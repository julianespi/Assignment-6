#pragma once
class courses
{
private:
	string courseName;
	MyBag<int> studentIDs;
	MyBag<string> studentNames;
	MyBag<double> studentScores;
	MyBag<char> grade;

public:
	//constuctor
	courses()
	{
		courseName = "";
		studentIDs.creationClearArray();
		studentNames.creationClearArray();
		studentScores.creationClearArray();
		grade.creationClearArray();
	}

	//copy constuctor
	courses(string newcousreName, MyBag<int> newstudentIDs, MyBag<string> newstudentNames, MyBag<double> newstudentScores, MyBag<char> newgrade)
	{
		courseName = newcousreName;
		for (int i = 0; i < newstudentIDs.getSize(); i++)
			studentIDs.insertElement(newstudentIDs.getelement(i));
		for (int i = 0; i < newstudentIDs.getSize(); i++)
			studentNames.insertElement(newstudentNames.getelement(i));
		for (int i = 0; i < newstudentIDs.getSize(); i++)
			studentScores.insertElement(newstudentScores.getelement(i));
		for (int i = 0; i < newstudentIDs.getSize(); i++)
			grade.insertElement(newgrade.getelement(i));
	}

	//Mutators
	//Pre Conditions: A string
	//post conditions: sets course name
	void setCourseName(string newCousreName)
	{
		courseName = newCousreName;
	}
	
	//Pre Conditions:a int
	//post conditions: add the student ID to a mybag class
	void setStudentID(int newStudentID)
	{
		studentIDs.insertElement(newStudentID);
	}

	//Pre Conditions: a string
	//post conditions: adds the string to a mybag class
	void setStudentName(string newStudentName)
	{
		studentNames.insertElement(newStudentName);
	}

	//Pre Conditions: a double 
	//post conditions: adds the double to a mybag class
	void setStudentScoreAndGrade(double newScore)
	{
		studentScores.insertElement(newScore);

		if (newScore >= 90)
			grade.insertElement('A');
		else if (newScore >= 80)
			grade.insertElement('B');
		else if (newScore >= 70)
			grade.insertElement('c');
		else if (newScore >= 60)
			grade.insertElement('D');
		else
			grade.insertElement('F');
	}
	
	//Acessors
	//Pre Conditions: none
	//post conditions: returns the class size
	const int getclassSize()
	{
		return studentNames.getSize();
	}

	//Pre Conditions: none
	//post conditions: returns the course name
	const string getCourseName()
	{
		return courseName;
	}
		
	//Pre Conditions: a int to servre as an index
	//post conditions: returns a student ID
	const int getStudentID(int index)
	{
		return studentIDs.getelement(index);
	}
	
	//Pre Conditions: a int to servre as an index
	//post conditions: returns the student name
	const string getStudentName(int index)
	{
		return studentNames.getelement(index);
	}

	//Pre Conditions: a int to servre as an index
	//post conditions: reutnrs the student score
	const double getStudentScore(int index)
	{
		return studentScores.getelement(index);
	}

	//Pre Conditions: a int to servre as an index
	//post conditions: Returns the student grade
	const char getStudentGrade(int index)
	{
		return grade.getelement(index);
	}

	//Class functions
	//Pre Conditions: none
	//post conditions: displays the class and students in the class.
	const void displaycourse()
	{
		cout << endl;
		cout << courseName << endl;
		cout << "Student ID's" << setw(15) << "Student Names" << setw(20) << "Student Score" << setw(15) << "Student Grade" << setw(3) << endl;
		double average = 0;
		for (int i = 0; i < studentIDs.getSize(); i++)
		{
			average += studentScores.getelement(i);
			cout << studentIDs.getelement(i) << setw(17) << studentNames.getelement(i) << setw(16) << studentScores.getelement(i) << setw(12) << grade.getelement(i) << endl;

		}

		average = average / studentIDs.getSize();
		string letterGrade = " ";
		if (average >= 90)
			letterGrade = "A";
		else if (average >= 80)
			letterGrade = "B";
		else if (average >= 70)
			letterGrade = "C";
		else if (average >= 60)
			letterGrade = "D";
		else
			letterGrade = "F";
		cout << endl;
		cout << "Average score and grade: " << average << " (" << letterGrade << ")" << endl;
	}


	//Pre Conditions: a int to serve as an index
	//post conditions: deletes all of a students info at an index
	void deleteStudent(int index)
	{
		studentIDs.removeElementAtIndex(index);
		studentNames.removeElementAtIndex(index);
		studentScores.removeElementAtIndex(index);
		grade.removeElementAtIndex(index);
	}


};

//Pre Conditions: the vecotor of class list.
//post conditions: specfies the number of classes taken
void specifyNumberOfClasses(vector<courses> &classList)
{
	int numberOfCourses = inputInteger("Enter the number of courses: ", 0, 8);
	classList.resize(numberOfCourses);
	cout << numberOfCourses << " courses have been created." << endl;;

}

//Pre Conditions: takes in a vector of courses  class refrence
//post conditions: fills the vectors with courses.
void readData(vector<courses> &classList)
{
	int maxClasses = classList.size();
	int index = 0;
	if (classList.size() == 0)
	{
		cout << " ERROR: number of courses has not been assigned." << endl;
		return;
	}
	classList.clear();
	while (index != maxClasses)
	{


		cout << "Enter a data file name for course[" << index << "] (STOP - return)" << endl;

		courses buffer;
		string fileName = inputString("Enter the name of the file: ", false);
		int newEmployeeIDIncrment = 0;

		if (fileName == "STOP")
			return;
		string correctFile = "input.dat";


		cout << "loading file..." << endl;

		ifstream file1;
		file1.open(fileName, ios::in);
		if (file1.fail())
		{
			cout << "ERROR: file cannot be read, try " << correctFile << endl;
		}
		else
		{
			string temp;
			int tempInt = 0;

			getline(file1, temp, '\n');
			buffer.setCourseName(temp);
			while (!file1.eof())
			{
				getline(file1, temp, ',');
				buffer.setStudentID(stoi(temp));
				getline(file1, temp, ',');
				buffer.setStudentName(temp);
				getline(file1, temp, '\n');
				buffer.setStudentScoreAndGrade(stod(temp));

			}
			classList.push_back(buffer);
			index++;
		}	
	}
	
}

//Pre Conditions: takes in a vector of courses.
//post conditions: displays weather or not the student is found based on name or id
const void searchForStudent(vector<courses> classList)
{
	if (classList.size() == 0)
	{
		cout << "ERROR: No data file has been read and stored into Courses." << endl;
		return;
	}

	cout << "3> Search by" << endl;
	cout << "==================" << endl;
	cout << "1. ID Number" << endl;
	cout << "2. Name" << endl;
	cout << "0. return" << endl;
	cout << "==================" << endl;
	int option = inputInteger("Option: ", 0, 2);

	if (option == 0)
		return;
	else if (option == 1)
	{
		int searchValue = inputInteger("Enter a student ID to search:", true);
		for (int c = 0; c < classList.size(); c++)
		{
			for (int i = 0; i < classList[c].getclassSize(); i++)
			{
				if (searchValue == classList[c].getStudentID(i))
				{
					cout << "ID: " << searchValue << " has been found in Course: " << classList[c].getCourseName() << endl;
					return;
				}
			}
		}
		cout << "No student ID: " << searchValue << " found." << endl;
	}
	else if (option == 2)
	{
		string searchValue = " ";
		searchValue += inputString("Enter a student name to search: ", true);
		for (int c = 0; c < classList.size(); c++)
		{
			for (int i = 0; i < classList[c].getclassSize(); i++)
			{
				if (searchValue == classList[c].getStudentName(i))
				{
					cout << "Name: " << searchValue << " has been found in Course: " << classList[c].getCourseName() << endl;
					return;
				}
					
			}
		}
		cout << "No student name " << searchValue << " found." << endl;
	}


}

//Pre Conditions: takes in a vector of courses.
//post conditions: finds and removes the student from a class or does nothing if the student isnt found
void removeStudent(vector<courses> &classList)
{
	if (classList.size() == 0)
	{
		cout << "ERROR: No data file has been read and stored into Courses." << endl;
		return;
	}

	cout << "4> Course(s)" << endl;
	cout << "=======================================================" << endl;
	int index;
	for (index = 0; index < classList.size(); index++)
	{
		cout << index + 1 << ". " << classList[index].getCourseName() << endl;
	}
	cout << "=======================================================" << endl;
	cout << index + 1 << ". " << "Retrun" << endl;
	cout << "=======================================================" << endl;
	int option = inputInteger("Option: ", 1,4);
	if (option == index + 1)
		return;
	else
	{
		int searchValue = inputInteger("Enter a student ID to search and delete: ", true);
		int currentID = 0;
		for (int i = 0; i < classList[option - 1].getclassSize(); i++)
		{
			currentID = classList[option - 1].getStudentID(i);
			if (searchValue == currentID)
			{
				cout << "ID: " << searchValue << " has been found in Course: " << classList[option - 1].getCourseName() << " and has been deleted." << endl;
				classList[option - 1].deleteStudent(i);
				return;
			}
		}
		cout << "No student ID: " << searchValue << " found." << endl;
	}



}

//Pre Conditions: takes in a vecotr of courses
//post conditions: displays the the option to see all the classes or only specific classes
const void displayClasses(vector<courses> classList)
{
	if (classList.size() == 0)
	{
		cout << "ERROR: No data file has been read and stored into Courses." << endl;
		return;
	}
	cout << "Course(s)" << endl;
	cout << "=======================================================" << endl;
	int index;
	for (index = 0; index < classList.size(); index++)
	{
		cout << index + 1 << ". " << classList[index].getCourseName() << endl;
	}
	cout << "=======================================================" << endl;
	cout << index + 1 << ". " << "All" << endl;
	cout << "=======================================================" << endl;

	int option = inputInteger("option: ", 1, index + 1);

	if (option == index + 1)
	{
		
		for (int i = 0; i < classList.size(); i++)
		{
			if (classList[i].getclassSize() == 0)
				cout << endl << classList[i].getCourseName() << " has not students." << endl;
			else
			classList[i].displaycourse();
		}
			
	}
	else
	{
		if (classList[option - 1].getclassSize() == 0)
			cout << endl << classList[option - 1].getCourseName() << " has not students." << endl;
		else
			classList[option - 1].displaycourse();
	}
}

//Pre Conditions: none
//post conditions: returns an int 
int apllicationMenuOption()
{
	cout << endl << "1> Template MyBag of double";
	cout << endl << "==========================================";
	cout << endl << "1 > Specify the number of courses";
	cout << endl << "2 > Read in data file and insert into courses";
	cout << endl << "3 > Search for a student record from a course";
	cout << endl << "4 > Remove a student record from a course";
	cout << endl << "5 > Display course(s)";
	cout << endl << "==========================================";
	cout << endl << "0. Exit";
	cout << endl << "==========================================" << endl;
	int options = inputInteger("Options: ", 0, 6);
	cout << endl << endl << endl;
	return options;
}

//Pre Conditions: none
//post conditions: chooses which function to run based on user input.
void ApplicationMyBag()
{
	vector<courses> classList;
	do
	{
		switch (apllicationMenuOption())
		{
		case 0: return; break;
		case 1: specifyNumberOfClasses(classList); break;
		case 2: readData(classList); break;
		case 3: searchForStudent(classList); break;
		case 4: removeStudent(classList); break;
		case 5: displayClasses(classList); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");

	} while (true);
}
