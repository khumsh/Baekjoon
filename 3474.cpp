#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://www.acmicpc.net/problem/3474

int n;

// n!�� ������ ���� �ִ� 0�� ���� ���ϱ�
// 0�� 10�� ������� ������, 10�� 2�� 5�� ��
// n!������ 2�� 5���� �ξ� ����
// ����, n!�� ���Ե� 5�� ������ ���ϸ� ��. 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	while(n--)
	{
		ll num, cnt = 0;
		cin >> num;
		
		// 5�� �ŵ������� ��� �����ϸ� num�� ���� ���� ���� ���� 
		for (ll i = 5; i <= num; i *= 5)
		{
			cnt += num / i; 
		}

		cout << cnt << "\n";
	}
	
	
	return 0;
}
