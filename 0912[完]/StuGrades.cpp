#include<iostream>
#include<iomanip>
using namespace std;
struct stu
{
	char Number[10];
	char Name[20];
	float English;
	float Amaths;//����
	float Intro2SE;//������ Introduction to Sotfware Engineering
};
int main()
{
	stu stuGrade[20] = {//��ʼ��
	{ "19160201","������",56.95,56.88,33 },
	{ "19160202","�ķ���",100,87.23,88 },
	{ "19160203","���",56,57,37 },
	{ "19160204","����",98,56.59,35 },
	{ "19160205","�һ���",88,65,37 },
	{ "19160206","����",22,55,34 },
	{ "19160207","��ͯ��",66,77,77 },
	{ "19160208","��ǰ",60,50,88.65 },
	{ "19160209","���ͷ",78,99,93 },
	{ "19160210","���˺�",73,85,56 },
	{ "19160211","uki",82,88,66.88 },
	{ "19160212","����̫",36.12,78,32 },
	{ "19160213","������",63,14.56,57 },
	{ "19160214","�����",68.95,13,86 },
	{ "19160215","�ؼ�",19,72,63.23 },
	{ "19160216","������",99,55.98,83 },
	{ "19160217","����Ժ",77,80.12,93 },
	{ "19160218","�Ŷ�",55,58.98,23.69 },
	{ "19160219","����",44,95,13 },
	{ "19160220","����",33,84.77,88.56 }
	};
	double averageEng, averageAmaths, averageIntr2SE;//ÿ�ſ�ƽ����
	float sumEng=0, sumAmaths=0, sumIntr2SE=0;//ÿ�ſ��ܷ�
	double average[20] = { 0 };
	int i = 0,j=0;
	for (i = 0; i < 20; i++)//����ÿ���˵�ƽ����
		average[i] = (stuGrade[i].Amaths + stuGrade[i].English + stuGrade[i].Intro2SE) / 3.0;
	for (i = 0; i < 20; i++)//����ÿ�ſ��ܷ�
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
	cout << "��Ӣ��ɼ�������"<<endl;
	cout << endl << setiosflags(ios::fixed) << setprecision(2)
		<< dec << left << setw(12) << "ѧ��"
		<< dec << left << setw(8) << "����"
		<< dec << left << setw(8) << "Ӣ��"
		<< dec << left << setw(8) << "����"
		<< dec << left <<setw(12)<< "������" 
		<<"ƽ����"<< endl;
	for (i = 0; i < 20;i++)
		cout << setiosflags(ios::fixed) << setprecision(2)
		<< dec << left << setw(12) << stuGrade[i].Number 
		<< dec << left << setw(8) << stuGrade[i].Name 
		<< dec << left << setw(8)<<stuGrade[i].English 
		<< dec << left << setw(8) << stuGrade[i].Amaths 
		<< dec << left << setw(12) << stuGrade[i].Intro2SE 
		<< dec<<left<<setw(8)<< average[i]<< endl;
	cout << endl << "Ӣ����֣�" << averageEng << endl
		<< "�������֣�" << averageAmaths << endl
		<< "���۾��֣�" << averageIntr2SE << endl;
		return 0;
}