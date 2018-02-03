#include<iostream>
using namespace std;
int BFmatching(char *s, char *t)
{
	int i = 0, j = 0;
	int n = strlen(s);
	int m = strlen(t);
	while ((i < n)&&(j < m))
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
	char s[] = "ababcabcacb", t[] = "hgj";
	int pos = BFmatching(s, t);
	cout << "s:" << s << "\nt:" << t << endl;
	cout << "Pos:" << pos + 1 << endl;
	if (pos == -1) cout << "Can't Find!\n";
	return 0;
}