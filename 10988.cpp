#include <bits/stdc++.h>
using namespace std;
// 10988 팰린드롬인지 확인하기
// 팰린드롬 : 거꾸로 읽어도 같은 단어 (회문) 

string str, temp;

void Solve1()
{
	bool ok = true;
	
	cin >> str;
	
	for (int i = 0; i < str.length() / 2; i++)
	{
		if (str[i] != str[str.length()-i-1])
		{
			ok = false;
			break;
		}
			
	}
	
	cout << ok;
}

void Solve2()
{
	cin >> str;
	temp = str;
	
	reverse(temp.begin(), temp.end());
	
	cout << (temp == str) << "\n";
}

int main()
{
	//Solve1();
	Solve2();
	
	return 0;
}
