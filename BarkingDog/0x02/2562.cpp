#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a[12], maxN = 0, maxIdx;
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
		if (maxN < a[i])
		{
			maxN = a[i];
			maxIdx = i + 1;
		}
	}
	
	cout << maxN << "\n" << maxIdx;
	
	return 0;
}
