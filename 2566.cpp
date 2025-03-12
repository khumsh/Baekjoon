#include<bits/stdc++.h>
using namespace std;

int mx = -1, a, b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int n;
			cin >> n;
			
			if (mx < n)
			{
				mx = n;
				a = i+1;
				b = j+1;
			}
		}
	}
	
	cout << mx << "\n";
	cout << a << " " << b << "\n";
	
	return 0;
}
