#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	list<char> password;
	auto cursor = password.begin();
	
	for (int i = 0; i < n; i++)
	{
		string str, res;
		cin >> str;
		
		password.clear();
		cursor = password.begin();
		
		for (char c : str)
		{
			if (c == '<')
			{
				if (cursor != password.begin()) cursor--;
			}
			else if (c == '>')
			{
				if (cursor != password.end()) cursor++;
			}
			else if (c == '-')
			{
				if (cursor != password.begin())
				{
					cursor--;
					cursor = password.erase(cursor);
				}
			}
			else
			{
				password.insert(cursor, c);
			}
		}
		
		for (char c : password) cout << c;
		
		cout << "\n";
	}
	
	
	
	return 0;
}
