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
				
				// ���������ڰ� �ƴѰ�� continue; 
				if (i + 1 < s.size())
				{
					continue;
				}
			}
			
			if (number != "")
			{
				string ret;
				
				// ���ڿ����� ó������ '0'�� �ƴ� ������ �ε����� ã���ϴ�.
			    int idx = 0;
			    while (idx < number.size() && number[idx] == '0') 
				{
			        idx++;
			    }
			    
			    // ��� ���ڰ� '0'�� ��� idx�� numStr.size()�� �������ϴ�.
			    if (idx == number.size()) 
				{
			        ret = "0";  // ���ڰ� ��� 0�̸� "0"�� ��ȯ
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
