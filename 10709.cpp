#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/10709

int h, w, a[101][101], cnt;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		cnt = -1;
		for (int j = 0; j < w; j++)
		{
			char c;
			cin >> c;
			
			if (c == 'c')
			{
				a[i][j] = 0;
				cnt = 0;
			}
			else if (c == '.')
			{
				if (cnt >= 0)
				{
					cnt++;
					a[i][j] = cnt;
				}
				else // cnt == -1
				{
					a[i][j] = -1;
				}
				
			}
			
		}
	}
	
	
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
