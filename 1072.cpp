#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX = 1e9;

ll x, y, z, ret = MAX;

ll getWinRate(ll total, ll win)
{
	return win * 100 / total;
}

bool check(ll mid)
{
	//cout << "z: " << z << ", mid: " << mid << ", winRate: " << getWinRate(x + mid, y + mid) << "\n";

	return getWinRate(x + mid, y + mid) > z;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> x >> y;
	z = getWinRate(x, y);
	
	// z가 99 이상이면 추가 게임을 해도 승률이 오르지 않으므로 바로 -1 출력
    if (z >= 99) 
	{
        cout << -1 << "\n";
        return 0;
    }
	
	ll l = 1, r = MAX, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			ret = min(mid, ret);
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	
	if (ret == MAX)
		ret = -1;
		
	cout << ret << "\n";
	
	return 0;
}
