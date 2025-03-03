#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, mxCnt, a[300004];
ll ret = 1e18;

// ������ k�� ���� �� �ִ��� Ȯ��. 
bool check(ll k)
{
	ll num = 0;
	for (int i = 0; i < m; i++)
	{
		num += a[i] / k;
		if (a[i] % k) num++;
	}
	
	return num <= n; // ������ ���� ������ �� �������� true 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// ������ �ּҰ� ���ϱ� ����...
	// ��� ������ ���ؼ�(for: 1 -> max ~~) Ǯ�⿣ ������ �ʹ� ����. (����Ž�� �Ұ�) 
	// => �������� n�� ��, �л����� ���� ������ ������ ������ �� �ִ��� Ȯ���ϴ� ����. 
	
	// �������� n�̸�, �ִ�� ������ �� �ִ� ������ n�̹Ƿ�, �л����� ���� n�� ���� �� �ִ��� Ȯ��.
	// ���� �� ������ �ּҰ� ������Ʈ �� �� ���� ������ ���� �� �ִ��� ����ؼ� Ȯ��.
	// ���� �� �������� �ּҰ� ���. 
	
	// input
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		
		mxCnt = max(mxCnt, a[i]);
	}
	
	//
	ll l = 1, r = mxCnt, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid)) // ������ mid���� ������ �� ������ 
		{
			ret = min(ret, mid);
			r = mid - 1; // �� ���� ���� �ִ��� ã�� 
		}
		else // ������ �� ������ �� ū������ ã�� 
		{
			l = mid + 1;
		}
	}
	
	cout << ret << "\n";
	
	
	return 0;
}
