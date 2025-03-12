#include<bits/stdc++.h>
using namespace std;

int n, a, b, sum, visited[104][104];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		
		for (int p = a; p < a + 10; p++)
		{
			for (int q = b; q < b + 10; q++)
			{
				if (!visited[p][q])
				{
					visited[p][q] = 1;
					sum++;
				}
			}
		}
		
	}
	
	cout << sum << "\n";
	
	
	return 0;
}
