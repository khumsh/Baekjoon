#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j > 0; j--)
		{
			if (j > i + 1) cout << " ";
			else cout << "*";
		}
		cout << "\n";
	}
	
	return 0;
}
