#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/9012

int t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	// input
	cin >> t;
	
	while(t--)
	{
		int sCnt = 0;
		int eCnt = 0;
		bool isVPS = true;
		
		string s;
		cin >> s;
		
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				sCnt++;
			}
			else if (s[i] == ')')
			{
				eCnt++;
				
				if (eCnt > sCnt)
				{
					isVPS = false;
					break;
				}
			}
		}
		
		if (sCnt > 0 && eCnt > 0 && sCnt == eCnt && isVPS)
		{
			cout << "YES\n"; 
		}
		else
		{
			cout << "NO\n";
		}
	}
	
	
	
	return 0;
}
