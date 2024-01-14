#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	list<char> text;
	list<char>::iterator cursor;
	
	string str;
	int m;
	
	cin >> str;
	cin >> m;
	
	for(char c : str) text.push_back(c);
	cursor = text.end();
	
	for(int i = 0; i < m; i++)
	{
		string cmd;
		cin >> cmd;
		
		if (cmd == "L")
		{
			if (cursor != text.begin()) cursor--;
		}
		else if (cmd == "D")
		{
			if (cursor != text.end()) cursor++;
		}
		else if (cmd == "B")
		{
			if (cursor != text.begin()) 
			{
				cursor--;
				cursor = text.erase(cursor);
			}
		}
		else if (cmd == "P")
		{
			char c;
			cin >> c;
			
			text.insert(cursor, c);
		}
	}
	
	for(auto t : text) cout << t;
	
	return 0;
}
