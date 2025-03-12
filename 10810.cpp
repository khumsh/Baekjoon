#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, c, cnt[104];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		
		for (int j = a; j <= b; j++)
		{
			cnt[j] = c;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		cout << cnt[i] << " ";
	}
	
	
	return 0;
}
