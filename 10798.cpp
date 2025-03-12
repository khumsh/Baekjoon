#include<bits/stdc++.h>
using namespace std;

int mx;
string a[5];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
		
		int size = a[i].size();
		mx = max(mx, size);
	}
	
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (a[j].size() > i)
				cout << a[j][i];
		}
	}
	
	
	return 0;
}
