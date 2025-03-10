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
	
	// mid�� ���� �� cnt���� �¿� �� ����.
	// n���� ���� �¿� �� ������ true. 
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
	
	// ���� ����ð�: t
	// t-1�ʱ��� �� ���� ������ ���
	cnt = m;
	for (ll i = 0; i < m; i++)
	{
		cnt += (t - 1) / a[i];
	}
	
	//cout << "t: " << t << ", cnt: " << cnt << "\n"; 
	
	// t�ʿ� ž���ϴ� ���̵� �߿��� n��° ���̰� �� ��° ���̱ⱸ�� ž���ϴ��� ����
	for (ll i = 0; i < m; i++)
	{
		// t�ʿ� i�� ���̱ⱸ�� ���̸� �¿� �� ������ 
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
