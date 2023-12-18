#include <bits/stdc++.h>
using namespace std;
// 2979 트럭 주차 

int a, b, c, m, n;
int cnt[104], sum;
int main()
{
	cin >> a >> b >> c;
	
	for(int i = 0; i < 3; i++)
	{
		cin >> m >> n;
		
		for(int j = m; j < n; j++)
		{
			cnt[j]++;
		}
	}
	
	for(int i = 1; i < 100; i++)
	{
		if (cnt[i] == 1)
			sum += a;
		else if (cnt[i] == 2)
			sum += b * 2;
		else if (cnt[i] == 3)
			sum += c * 3;
		
	}
	
	cout << sum;
	
	return 0;
}
