#include<bits/stdc++.h>
using namespace std;

string s;
int a, b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
			
		if (b % a == 0)
		{
			s = "factor";
		}
		else if (a % b == 0)
		{
			s = "multiple";
		}
		else
		{
			s = "neither";
		}
		
		cout << s << "\n";
	}
	
	return 0;
}
