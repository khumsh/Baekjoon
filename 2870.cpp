#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/2870

int n;
vector<string> v;
string s, number;

bool is_number(char c)
{
	return (c >= '0' && c <= '9');
}

bool cmp (const string &s1, const string &s2)
{
	if (s1.size() == s2.size())
		return s1 < s2;
		
	return s1.size() < s2.size();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n;
	while(n--)
	{
		cin >> s;
		
		number = "";
		
		for (int i = 0; i < s.size(); i++)
		{
			if (is_number(s[i]))
			{
				number += s[i];
				
				// 마지막글자가 아닌경우 continue; 
				if (i + 1 < s.size())
				{
					continue;
				}
			}
			
			if (number != "")
			{
				string ret;
				
				// 문자열에서 처음으로 '0'이 아닌 문자의 인덱스를 찾습니다.
			    int idx = 0;
			    while (idx < number.size() && number[idx] == '0') 
				{
			        idx++;
			    }
			    
			    // 모든 문자가 '0'인 경우 idx가 numStr.size()와 같아집니다.
			    if (idx == number.size()) 
				{
			        ret = "0";  // 숫자가 모두 0이면 "0"을 반환
			    }
			    else
			    {
			    	ret = number.substr(idx);
				}
				
				v.push_back(ret);
				
				number = "";
			}
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for (auto it : v)
	{
		cout << it << "\n";
	}
	
	return 0;
}
