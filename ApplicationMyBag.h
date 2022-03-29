class courses
{
private:
	string courseName;
	MyBag<int> studentIDs;
	MyBag<string> studentNames;
	MyBag<double> studentScores;
	MyBag<char> grade;

public:

	courses()
	{
		courseName = "";
		studentIDs.creationClearAry();
		studentNames.creationClearAry();
		studentScores.creationClearAry();
		grade.creationClearAry();
	}

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

	void setCourseName(string newCousreName)
	{
		courseName = newCousreName;
	}
	
	void setStudentID(int newStudentID)
	{
		studentIDs.insertElement(newStudentID);
	}

	void setStudentName(string newStudentName)
	{
		studentNames.insertElement(newStudentName);
	}

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

	string getCourseName()
	{
		return courseName;
	}
		
	int getStudentID(int index)
	{
		return studentIDs.getelement(index);
	}
		
	string getStudentName(int index)
	{
		return studentNames.getelement(index);
	}

	double getStudentScore(int index)
	{
		return studentScores.getelement(index);
	}

	char getStudentGrade(int index)
	{
		return grade.getelement(index);
	}

	void displaycourse()
	{
		cout << courseName << endl;
		cout << "Student ID's" << setw(15) << "Student Names" << setw(20) << "Student Score" << setw(15) << "Student Grade" << setw(3) << endl;
		double average = 0;
		for (int i = 0; i < studentIDs.getSize(); i++)
		{
			average += studentScores.getelement(i);
			cout << studentIDs.getelement(i) << setw(17)   << studentNames.getelement(i) << setw(16)  << studentScores.getelement(i) << setw(12) << grade.getelement(i) << endl;
			
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

		cout << "Average score and grade: " << average << " (" << letterGrade << ")" << endl;
	}

};
