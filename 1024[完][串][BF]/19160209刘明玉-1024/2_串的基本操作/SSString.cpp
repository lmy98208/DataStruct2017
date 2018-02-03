#include<iostream>
#include<string>
using namespace std;
#define MaxSize 12

void StrCat(char *s1, char *s2)//串连接
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 + len2 > MaxSize - 1)
	{
		cerr << "超长\n";
		exit(1);
	}
	int i = 0;
	while (s2[i] != '\0')
	{
		s1[i + len1] = s2[i];//依次将s2赋到s1后面
		i++;
	}
	s1[i + len1] = '\0';//在连接好的s1后面加上字符串结束标志‘\0’
}

int StrCmp(char *s1, char* s2)
{
	int i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void StrCpy(char *s1, char *s2)
{
	int len = strlen(s2);
	if (len > MaxSize - 1)
	{
		cerr << "超长";
		exit(1);
	}
	int i = 0;
	while (*s1++ = *s2++);//把s2依次赋给s1，直到读到s2的‘\0’
}

int main()
{
	char s1[12] = "Hello", s2[6] = "World";
	cout << "s1=" << s1 << "   s2=" << s2 << endl;
	StrCat(s1, s2);
	cout << "s1+s2=" << s1 << endl;
	//char s3[6]="Hello";
	int k = StrCmp(s1, s2);
	cout << "s1";
	if (k == 0) cout << "=";
	else if (k > 0) cout << ">";
	else cout << "<";
	cout << "s2" << endl;
	StrCpy(s1, s2);
	cout << "s2拷贝给s1后的s1为:" << s1 << endl;
	return 0;
}