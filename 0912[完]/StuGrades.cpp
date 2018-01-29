#include<iostream>
#include<iomanip>
using namespace std;
struct stu
{
	char Number[10];
	char Name[20];
	float English;
	float Amaths;//高数
	float Intro2SE;//软工导论 Introduction to Sotfware Engineering
};
int main()
{
	stu stuGrade[20] = {//初始化
	{ "19160201","鸡蛋羹",56.95,56.88,33 },
	{ "19160202","的防护",100,87.23,88 },
	{ "19160203","风格化",56,57,37 },
	{ "19160204","热土",98,56.59,35 },
	{ "19160205","桃花运",88,65,37 },
	{ "19160206","而已",22,55,34 },
	{ "19160207","儿童期",66,77,77 },
	{ "19160208","日前",60,50,88.65 },
	{ "19160209","软骨头",78,99,93 },
	{ "19160210","天人合",73,85,56 },
	{ "19160211","uki",82,88,66.88 },
	{ "19160212","二姨太",36.12,78,32 },
	{ "19160213","阿切托",63,14.56,57 },
	{ "19160214","万恶他",68.95,13,86 },
	{ "19160215","回家",19,72,63.23 },
	{ "19160216","受托人",99,55.98,83 },
	{ "19160217","话剧院",77,80.12,93 },
	{ "19160218","才对",55,58.98,23.69 },
	{ "19160219","讨厌",44,95,13 },
	{ "19160220","你们",33,84.77,88.56 }
	};
	double averageEng, averageAmaths, averageIntr2SE;//每门课平均分
	float sumEng=0, sumAmaths=0, sumIntr2SE=0;//每门课总分
	double average[20] = { 0 };
	int i = 0,j=0;
	for (i = 0; i < 20; i++)//计算每个人的平均分
		average[i] = (stuGrade[i].Amaths + stuGrade[i].English + stuGrade[i].Intro2SE) / 3.0;
	for (i = 0; i < 20; i++)//计算每门课总分
	{
		sumEng += stuGrade[i].English;
		sumAmaths += stuGrade[i].Amaths;
		sumIntr2SE += stuGrade[i].Intro2SE;
	}
	averageEng = sumEng / 20.0;
	averageAmaths = sumAmaths / 20.0;
	averageIntr2SE = sumIntr2SE / 20.0;
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < (19 - i); j++)
		{
			if (stuGrade[j].English <= stuGrade[j + 1].English)
			{
				stu temp = stuGrade[j];
				stuGrade[j] = stuGrade[j + 1];
				stuGrade[j+1] = temp;
			}
		}
	}
	cout << "按英语成绩排名："<<endl;
	cout << endl << setiosflags(ios::fixed) << setprecision(2)
		<< dec << left << setw(12) << "学号"
		<< dec << left << setw(8) << "姓名"
		<< dec << left << setw(8) << "英语"
		<< dec << left << setw(8) << "高数"
		<< dec << left <<setw(12)<< "软工导论" 
		<<"平均分"<< endl;
	for (i = 0; i < 20;i++)
		cout << setiosflags(ios::fixed) << setprecision(2)
		<< dec << left << setw(12) << stuGrade[i].Number 
		<< dec << left << setw(8) << stuGrade[i].Name 
		<< dec << left << setw(8)<<stuGrade[i].English 
		<< dec << left << setw(8) << stuGrade[i].Amaths 
		<< dec << left << setw(12) << stuGrade[i].Intro2SE 
		<< dec<<left<<setw(8)<< average[i]<< endl;
	cout << endl << "英语均分：" << averageEng << endl
		<< "高数均分：" << averageAmaths << endl
		<< "导论均分：" << averageIntr2SE << endl;
		return 0;
}