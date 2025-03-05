#include<bits/stdc++.h>
using namespace std;

int n, m, sum, ret = 1e9, a[100004];

bool check(int mid)
{
	int cnt = 1, curMoney = mid;
	for (int i = 0; i < n; i++)
	{
		if (curMoney < a[i])
		{
			curMoney = mid;
			cnt++;
		}
		curMoney -= a[i];
		
		if (curMoney < 0)
			return false;
	}
	
	return cnt <= m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	//
	int l = 1, r = sum, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			ret = min(ret, mid);
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	
	cout << ret << "\n";
	
	return 0;
}
