#include <bits/stdc++.h>
using namespace std;
// 1159 ³ó±¸ °æ±â 

int n, cnt[26];
string temp, r = "";

void Solve1()
{
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		int idx = (int)temp[0] - 97;
		cnt[idx]++;
	}
	
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] >= 5)
		{
			r += (char)(i + 97);
		}
	}
	
	if (r.length() > 0)
		cout << r;
	else
		cout << "PREDAJA";
}

void Solve2()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		cnt[temp[0] - 'a']++;
	}
	
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] >= 5)
			r += (i + 'a');
	}
	
	if (r.size())
		cout << r << "\n";
	else
		cout << "PREDAJA" << "\n";
} 

int main()
{
	//Solve1();
	Solve2();
	
	return 0;
}
