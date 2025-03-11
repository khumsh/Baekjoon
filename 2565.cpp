#include<bits/stdc++.h>
using namespace std;

int n, len, lis[504];

const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++)
	{
		// ���� ������, ������ ������ 
		cin >> a[i].first >> a[i].second;
	}
	
	// ���� ������ �������� ���� 
	sort(a.begin(), a.end());
	
	// ������ �����밡 ���������̸� ��������.
	// => LIS (���� ���� �κ� ����) 
	fill(lis, lis + 504, INF);
	for (int i = 0; i < n; i++)
	{
		int pos = lower_bound(lis, lis + len, a[i].second) - lis;
		
		lis[pos] = a[i].second;
		
		if (pos == len) len++;
	}
	
	cout << n - len << "\n";
	
	return 0;
}
