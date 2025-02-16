#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/2828

int n, m, j, a[21];
int l, r, ret;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> m;
	cin >> j;
	for (int i = 0; i < j; i++)
	{
		cin >> a[i];
	}
	
	// �ʱ� ��ġ 
	l = 1;
	r = l + m - 1;
	
	for (int i = 0; i < j; i++)
	{
		// �ٱ��ϰ� �ִ� ������ �������� ���� �� 
		if (a[i] >= l && a[i] <= r)
		{
			continue;
		}
		
		// �ٱ��ϰ� ���� ������ �������� ���� ��
		if (a[i] > r) // ������ 
		{
			int length = a[i] - r;
			ret += length;
			l += length;
			r += length;
		}
		else if (a[i] < l) // ���� 
		{
			int length = l - a[i];
			ret += length;
			l -= length;
			r -= length;
		}
	}
	
	cout << ret << "\n";
	
	return 0;
}
