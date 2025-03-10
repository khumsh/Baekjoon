#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, y, z, ret = -1;

ll getWinRate(ll total, ll win)
{
	return win * 100 / total;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> x >> y;
	z = getWinRate(x, y);
	
	ll l = 1, r = 1e9, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (getWinRate(x + mid, y + mid) > z)
		{
			ret = mid;
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
