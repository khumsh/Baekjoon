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
	
	// 초기 위치 
	l = 1;
	r = l + m - 1;
	
	for (int i = 0; i < j; i++)
	{
		// 바구니가 있는 곳으로 떨어지고 있을 때 
		if (a[i] >= l && a[i] <= r)
		{
			continue;
		}
		
		// 바구니가 없는 곳으로 떨어지고 있을 때
		if (a[i] > r) // 오른쪽 
		{
			int length = a[i] - r;
			ret += length;
			l += length;
			r += length;
		}
		else if (a[i] < l) // 왼쪽 
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
