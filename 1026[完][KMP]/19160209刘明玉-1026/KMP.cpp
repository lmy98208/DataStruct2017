#include<iostream>
using namespace std;

void getnext(char *t,int next[])
{
	int j = 0, k = -1;
	int m = strlen(t);
	next[0] = -1;
	while (j < m - 1)
	{
		if (k == -1 || t[j] == t[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}

int KMPmatching(char* s, char*t,int next[])
{
	int i = 0, j = 0;
	int n = strlen(s), m = strlen(t);
	while (i < n&&j < m)
	{
		if (j == -1 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j >= m)
		return i - m;
	else
		return -1;
}
int main()
{
	int next[100];
	char s[] = "ababcabcacb", t[] = "acb";
	getnext(t, next);
	int pos = KMPmatching(s, t, next);
	cout << "s:" << s << "\nt:" << t << endl;
	if (pos < 0) cout << "Can't find.\n";
	else
		cout << "Pos:" << pos+1 << endl;
	return 0;
}