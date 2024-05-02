#include<bits/stdc++.h>
using namespace std;
// 1940 аж╦Ы 

int n, m, t, cnt, a[15004];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			t = a[i] + a[j];
			
			if (t == m)
				cnt++;
		}
	} 
	
	cout << cnt << "\n";
}
