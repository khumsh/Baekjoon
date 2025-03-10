#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, a[10004], cnt, t;

bool check(ll mid)
{
	cnt = m;
	for (ll i = 0; i < m; i++)
	{
		cnt += (mid / a[i]);
	}
	
	// mid분 동안 총 cnt명을 태울 수 있음.
	// n명을 전부 태울 수 있으면 true. 
	return cnt >= n;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (ll i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	
	if (n <= m)
	{
		cout << n << "\n";
		return 0;
	}
	
	ll l = 0, r = 60000000004, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			t = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	
	// 최적 운행시간: t
	// t-1초까지 몇 명이 탔는지 계산
	cnt = m;
	for (ll i = 0; i < m; i++)
	{
		cnt += (t - 1) / a[i];
	}
	
	//cout << "t: " << t << ", cnt: " << cnt << "\n"; 
	
	// t초에 탑승하는 아이들 중에서 n번째 아이가 몇 번째 놀이기구에 탑승하는지 결정
	for (ll i = 0; i < m; i++)
	{
		// t초에 i번 놀이기구가 아이를 태울 수 있으면 
		if (t % a[i] == 0)
		{
			cnt++;
		}
		if (cnt == n)
		{
			cout << i + 1 << "\n";
			return 0;
		}
	} 
	
	
	return 0;
} 
