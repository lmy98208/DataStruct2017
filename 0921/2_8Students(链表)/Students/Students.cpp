#include"Students.h"
#include<string>
#include<iostream>
using namespace std;

Student::Student(int num, int classnum, string name, score g[])
{
	Number = num;
	ClassNum = classnum;
	Name = name;
	for (int i = 0; i < 2; i++)
	{
		gra[i].course = g[i].course;
		gra[i].grade = g[i].grade;
	}
}

void Student::SetNum(int num)
{
	Number = num;
}

void Student::SetClassNum(int classnum)
{
	ClassNum = classnum;
}

Student Student::operator=(const Student & S)
{
	if (this == &S) return *this;
	Number = S.Number;
	Name = S.Name;
	ClassNum = S.ClassNum;
	for (int i = 0; i < 2; i++)
	{
		gra[i].course = S.gra[i].course;
		gra[i].grade = S.gra[i].grade;
	}
	return *this;
}

ostream & operator<<(ostream & o, Student & S)
{
	o << '\t' << S.Number << '\t'
		<< S.Name << '\t' << S.ClassNum
		<< '\t' << S.gra[0].course<<'\t'<<S.gra[0].grade 
		<< '\t' << S.gra[1].course << '\t' << S.gra[1].grade << endl;
	return o;
}

istream & operator >> (istream & i, Student & S)
{
	i >> S.Number >> S.Name >> S.ClassNum >> S.gra[0].course>>S.gra[0].grade
		>>S.gra[1].course>>S.gra[1].grade;
	return i;
}
