#include <iostream>  
#include <math.h>  
using namespace std;

int triangle(int x, int y) 
{   
	if (y == 1 || y == x)
		return 1;
	return triangle(x - 1, y - 1) + triangle(x - 1, y);
}

int main( )
{
	cout << "请输入行数：";
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j<2 * n - 2 * i + 1; j++)
			cout<<" ";//打印空格  
		for (int j = 1; j <= i; j++)
			printf("%4d", triangle(i, j)); 

		printf("\n");
	}
	return 0;
}