#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, sAtk, t[1000004], a[1000004], h[1000004];

bool check(ll mid)
{
	ll hp = mid;
	ll atk = sAtk;
	
	for (int i = 0; i < n; i++)
	{
		if (t[i] == 1)
		{
			// 몬스터 있는 방
			ll monsterAtk = a[i], monsterHp = h[i];
			
			ll cnt = monsterHp / atk + (monsterHp % atk ? 1 : 0);
			hp -= (cnt - 1) * monsterAtk;
		}
		else
		{
			atk += a[i];
			hp = min (mid, hp + h[i]);
		} 
		
		if (hp <= 0)
			return false;
	}
	
	return true;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> sAtk;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i] >> a[i] >> h[i];
	}
	
	//
	ll l = 1, r = 1e18, mid, ret = 1e18;
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
