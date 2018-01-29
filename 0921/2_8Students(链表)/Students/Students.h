#include<iostream>
#include<string>
using namespace std;
struct score
{
	string course;
	float grade;
};

class Student
{
private:
	int Number;
	int ClassNum;
	string Name;
	score gra[2];
public:
	Student() {}
	Student(int num, int classnum, string name, score g[]);
	~Student() {}
	int GetNum() { return Number; }
	void SetNum(int num);  //修改学号
	void SetClassNum(int classnum) ; //修改班级号
	Student operator=(const Student &S); //操作符重载
	friend ostream & operator<<(ostream &o, Student &S);
	friend istream & operator >> (istream &i, Student &S);
};
