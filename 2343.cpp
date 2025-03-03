#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, mx, a[100004];
ll sum, ret = 1e18;

// ���� �뷮(mid)�� m�� ������ ��緹�̿� ���� �������� 
bool check(int mid)
{
	int cnt = 1;
	ll currentSum = 0;
	for (int i = 0; i < n; i++)
	{
		if (currentSum + a[i] <= mid)
		{
			currentSum += a[i];
		}
		else
		{
			currentSum = a[i];
			cnt++;
		}
	}
	
	// m�� ������ ��緹�̷� ��� ���Ǹ� ���� �� ������ true 
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
		mx = max(mx, a[i]);
		sum += a[i];
	}
	
	//
	ll l = mx, r = sum, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid)) // m�� ���Ϸ� ��� ���Ǹ� ���� �� ������ �뷮 �ٿ����� 
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
