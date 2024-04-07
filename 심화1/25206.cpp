#include <iostream>
#include <vector>
using namespace std;

class MajorInfo
{
public:
	MajorInfo(string major, double credit, string grade);
	double GetGradeToDouble();
	double GetCredit();

private:
	string major;
	double credit;
	string grade;
};

MajorInfo::MajorInfo(string major, double credit, string grade)
{
	this->major = major;
	this->credit = credit;
	this->grade = grade;
}

double MajorInfo::GetGradeToDouble()
{
	double ret = -1;

	if (this->grade == "A+")
	{
		ret = 4.5;
	}
	else if (this->grade == "A0")
	{
		ret = 4.0;
	}
	else if (this->grade == "B+")
	{
		ret = 3.5;
	}
	else if (this->grade == "B0")
	{
		ret = 3.0;
	}
	else if (this->grade == "C+")
	{
		ret = 2.5;
	}
	else if (this->grade == "C0")
	{
		ret = 2.0;
	}
	else if (this->grade == "D+")
	{
		ret = 1.5;
	}
	else if (this->grade == "D0")
	{
		ret = 1.0;
	}
	else if (this->grade == "F")
	{
		ret = 0.0;
	}
	else if (this->grade == "P")
	{
		ret = -1.0;
	}

	return ret;
}

double MajorInfo::GetCredit()
{
	return this->credit;
}

int main()
{
	string major, grade;
	double credit;

	vector<MajorInfo> majorInfos;
	majorInfos.reserve(20);

	for (int i = 0; i < 20; i++)
	{
		cin >> major >> credit >> grade;
		majorInfos.push_back(MajorInfo(major, credit, grade));
	}
	
	double sumOfCredit = 0;
	double sumOfGrade = 0;

	for (int i = 0; i < majorInfos.size(); i++)
	{
		double gradeDouble = majorInfos[i].GetGradeToDouble();
		if (gradeDouble == -1.0)
		{
			continue;
		}

		sumOfCredit += majorInfos[i].GetCredit();
		sumOfGrade += majorInfos[i].GetCredit() * gradeDouble;
	}

	cout << fixed;
	cout.precision(6);
	cout << sumOfGrade / sumOfCredit;

	return 0;
}