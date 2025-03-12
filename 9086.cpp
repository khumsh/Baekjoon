#include<bits/stdc++.h>
using namespace std;

int t;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while(t--)
	{
		cin >> s;
		cout << s[0] << s[s.size()-1] << "\n";
	}
	
	return 0;
}
