#include <bits/stdc++.h>
using namespace std;
//11655 ROT13

string s, ret;

bool IsAlphabet_S(char c)
{
	return (c >= 'a' && c <= 'z');
}

bool IsAlphabet_C(char c)
{
	return (c >= 'A' && c <= 'Z');
}

void Solve1()
{
	getline(cin, s); 
	// ���鵵 �����Ͽ� �޾ƾ� �� �� : getline
	// ���� ������ : cin 
	
	for(int i = 0; i < s.size(); i++)
	{
		if (IsAlphabet_S(s[i]))
		{
			if (IsAlphabet_S(s[i] - 13))
				ret += s[i] - 13;
			else
				ret += s[i] + 13;
		}
		else if (IsAlphabet_C(s[i]))
		{
			if (IsAlphabet_C(s[i] - 13))
				ret += s[i] - 13;
			else
				ret += s[i] + 13;
		}
		else
			ret += s[i];
	}
	
	cout << ret;
}

void Solve2()
{
	getline(cin, s);
	
	for(int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] < 'z')
		{
			if (s[i] + 13 > 'z')
				s[i] = s[i] + 13 - 26; // 26�� ���� ó������ (z �Ѿ�� a��) 
			else
				s[i] = s[i] + 13;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			if (s[i] + 13 > 'Z')
				s[i] = s[i] + 13 - 26;
			else
				s[i] = s[i] + 13;
		}
	}
	
	cout << s;
}

int main()
{
	//Solve1();
	Solve2();
	
	return 0;
}
