#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, cnt[104];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cnt[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		
		int j = 0;
		while (a + j < b - j)
		{
			int temp = cnt[a+j];
			cnt[a+j] = cnt[b-j];
			cnt[b-j] = temp;
			
			j++;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		cout << cnt[i] << " ";
	}
	
	
	return 0;
}
