#include<iostream>
#include<time.h>
#include<stdlib.h>
#define random(x) (rand()%x)
using namespace std;

void sortBool(int arry_[], int k)
{
	int i = 0, j = 0;
	bool flag = true;
	for (i = 0; i<(k - 1) && flag; i++)
	{
		flag = false;
		for (j = 0; j<k - 1 - i; j++)
		{
			if (arry_[j]>arry_[j + 1])
			{
				int temp = arry_[j];
				arry_[j] = arry_[j + 1];
				arry_[j + 1] = temp;
				flag = true;
			}
		}
	}
}
void sortBasic(int arry[],int k)
{
	int i = 0,j;
	for (i = 0; i<(k - 1); i++)
	{
		for (j = 0; j<k - 1 - i; j++)
		{
			if (arry[j]>arry[j + 1])
			{
				int temp = arry[j];
				arry[j] = arry[j + 1];
				arry[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int i = 0, k = 80000, j = 0;
	int arry[80000] = { 0 }, arry_[80000] = { 0 };
	double totaltimeBasic[5], totaltimeBool[5];//运行5次，记录时间
	for (j = 0; j < 5;j++)
	{
		for (i = 0; i < k; i++)//10w个随机数
		{
			arry[i] = random(1000);//防止随机数过大在int中溢出
			arry_[i] = arry[i];
		}
		clock_t start, finish;
		
		start = clock();
		sortBasic(arry, k);
		finish = clock();
		totaltimeBasic[j] = (double)(finish - start) / CLOCKS_PER_SEC;

		start = clock();
		sortBool(arry_, k);
		finish = clock();
		totaltimeBool[j] = (double)(finish - start) / CLOCKS_PER_SEC;

	}

	for (j = 0; j < 5; j++)
		cout << "totaltimeBasic: " << totaltimeBasic[j] <<" s"<< endl
		<< "totaltimeBool: " << totaltimeBool[j]<<" s" << endl << endl;
	return 0;
}