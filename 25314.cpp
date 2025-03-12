#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	
	cin >> n;
	for (int i = 0; i < n/4; i++)
	{
		s += "long ";
	}
	
	cout << s << "int";
	
	return 0;
}
