#include<iostream>
#include<string>
#include"SeqStack.cpp"
using namespace std;

int IsMatch(int a, char b)//±»Ωœµ±«∞¿®∫≈”Î’ª∂•¿®∫≈ «∑Ò∆•≈‰
{
	if (a == '('&&b == ')')
		return 1;
	else if (a == '['&&b == ']')
		return 1;
	else if (a == '{'&&b == '}')
		return 1;
	else
		return 0;
}
int main()
{
	SeqStack<int, 100> a;
	cout << "«Î ‰»Î“ª∏ˆ±Ì¥Ô Ω£∫";
	string str;
	cin >> str;
	int flag = 1;
	int k = str.size();
	for (int i = 0; i < k; i++)
	{
		switch (str[i])
		{
		case '(':
		case '[':
		case '{':
			a.Push(str[i]);//◊Û¿®∫≈»´≤ø»Î’ª
			break;
		case ')':
		case ']':
		case '}':
			if (a.IsEmpty())//»Áπ˚∂¡µΩ¡À”“¿®∫≈µ´’ªŒ™ø’£¨‘Ú»±…Ÿ◊Û¿®∫≈
			{
				cout << "»±…Ÿ◊Û¿®∫≈£°\n";
				exit(1);
			}
			else
			{
				if (IsMatch(a.Top(), str[i]))//»Ù¿®∫≈∆•≈‰‘Ú◊Û¿®∫≈≥ˆ’ª
					int m=a.Pop();
				else 
				{
					cout << "”“¿®∫≈≤ª∆•≈‰£°\n";//∑Ò‘ÚŒ™”“¿®∫≈≤ª∆•≈‰
					exit(1);
				}
			}
		default: break;//∂¡µΩ∆‰À˚◊÷∑˚≤ª◊ˆ¥¶¿Ì
		}
	}

	if (a.IsEmpty()) cout << "¿®∫≈∆•≈‰£°\n";//∂¡ÕÍ ±’ªø’‘Ú∆•≈‰
	else cout << "»±…Ÿ”“¿®∫≈£°\n";//∂¡ÕÍ ±’ª÷–»‘”–◊Û¿®∫≈£¨‘Ú»±…Ÿ”“¿®∫≈

	return 0;

}