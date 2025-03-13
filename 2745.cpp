#include<bits/stdc++.h>
using namespace std;

string n;
int a, b, ret;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> b;
	for (int i = 0; i < n.size(); i++)
	{
		char c = n[i];
		
		if (c >= '0' && c <= '9')
		{
			a = c - '0';
		}
		else if (c >= 'A' && c <= 'Z')
		{
			a = c - 'A' + 10;
		}
		
		ret += pow(b, n.size() - 1 - i) * a;
	}
	
	cout << ret << "\n";
	
	return 0;
}
