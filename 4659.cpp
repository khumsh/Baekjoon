#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/4659

string s; 

bool is_vowel(char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool check1(string password)
{
	for (int i = 0; i < password.size(); i++)
	{
		if (is_vowel(password[i]))
			return true;
	}
	
	return false;
}

bool check2(string password)
{
	int cnt = 1;
	bool last_vowel = is_vowel(password[0]); // 마지막이 모음이었는지 
	
	for (int i = 1; i < password.size(); i++)
	{
		if (last_vowel == is_vowel(password[i])) // 마지막과 모음/자음 분류가 같으면 카운트 증가 
		{
			cnt++;
		}
		else
		{
			last_vowel = !last_vowel;
			cnt = 1;
		}
		
		if (cnt >= 3)
			return false;
	} 
	
	return true;
}

bool check3(string password)
{
	char last_char = password[0];
	
	for (int i = 1; i < password.size(); i++)
	{
		if (last_char == password[i]) // 마지막과 모음/자음 분류가 같으면 카운트 증가 
		{
			if (last_char != 'e' && last_char != 'o')
				return false;
		}
		else
		{
			last_char = password[i];
		}
	} 
	
	return true;
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(s != "end")
	{
		cin >> s;
		
		if (s == "end")
			break;
		
		if (check1(s) && check2(s) && check3(s))
			cout << "<" << s << "> is acceptable." << "\n";
		else
			cout << "<" << s << "> is not acceptable." << "\n";
	}
	
	return 0;
}
