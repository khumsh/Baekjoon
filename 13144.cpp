#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[100004], cnt[100004];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	
	ll l = 0, ret = 0;
	for (int r = 0; r < n; r++)
	{
		// ī��Ʈ ���� 
		cnt[a[r]]++;
		
		// ī��Ʈ�� 2ȸ �̻��� ��
		// �ߺ� ������ ���� ������ ����
		while (cnt[a[r]] > 1)
		{
			cnt[a[l]]--;
			l++;
		}
		
		// ���� �� ���� ����
		// [l, r] ������ �ߺ� ����. 
		// ������ ���� r�� �����ϸ�, ���� ���� l���� r���� ���� 
		ret += (r - l + 1);
	}
	
	cout << ret << "\n";
	
	return 0;
}
