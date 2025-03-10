#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s, c, sum, a[1000004];

bool check(ll mid)
{
	ll res = 0;
	for (int i = 0; i < s; i++)
	{
		res += a[i] / mid; 
	}
	
	//cout << "mid: " << mid << ", res: " << res << "\n";
	
	//  mid��ŭ�� ���̷� �Ĵ��� c�� �̻� ���� �� ������ true 
	return res >= c;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> c;
	for (int i = 0; i < s; i++)
	{
		cin >> a[i];
		
		sum += a[i];
	}
	
	ll l = 1, r = 1e9, mid, res = 1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			// �Ĵ߿� �� ���� ���̸� �� �÷����� 
			res = mid;
			l = mid + 1;
		}
		else
		{
			// �Ĵ� c�� ���� �Ұ� 
			// �� ���� �� �� �ٿ����� 
			r = mid - 1;
		}
	}
	
	cout << sum - res * c << "\n";
	
	
	return 0;
}
