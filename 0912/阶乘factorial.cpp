#include<iostream>
using namespace std;
int f(int m)
{
	static long pro = 1;
	pro = pro*m;
	return(pro);
}

int main()
{
	cout << "����׳ˣ�  " << endl
		<< "1!+2!+3!����+n!" << endl;
	cout << endl<<"������n��" << endl;
	int num,i=0,outcome=0;
	cin >>num;
	for (i = 1; i <= num; i++)
		outcome = f(i);
	cout << "1!+2!+3!����+"<<num<<"! = " 
		<< outcome<<endl;
	return 0;
}