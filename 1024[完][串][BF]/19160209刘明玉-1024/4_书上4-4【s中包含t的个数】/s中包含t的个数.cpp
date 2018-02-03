#include<iostream>
using namespace std;

int BFmatching(char *s, char *t)
{
	int i = 0, j = 0;
	int n = strlen(s);
	int m = strlen(t);
	while ((i < n) && (j < m))
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= m)
		return i - j;
	else
		return -1;
}

int main()
{
//	int next[100];
	char s[50], t[50];
	cout << "ÇëÊäÈë×Ö·û´®s£º";
	cin >> s;
	cout << "ÇëÊäÈë×Ö·û´®t£º";
	cin >> t;
	int pos = 0, count = 0;
	int i = 0;
	int len = strlen(s);
	int len_ = strlen(t);
	int tmp[20];
	memset(tmp, 0, sizeof(int) * 20);
	cout << "s:" << s << "\nt:" << t << endl;
	while (i<len)
	{
		cout << pos + 1 <<"  "<<i<< "  "<<count  << endl;
		int temp = BFmatching(s+i, t);
		if (temp != -1&&tmp[temp]!=1)
		{
			tmp[temp] = 1;
			pos = temp;
			count++;
			i = i + len_;
		}
		else i++;
	}
	cout << "Count:" << count << endl;
	return 0;
}