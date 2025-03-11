#include<bits/stdc++.h>
using namespace std;

int n, a[1004], lis[1004], len, ret;

const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	fill(lis, lis + 1004, INF);
	
	for (int i = 0; i < n; i++)
	{
		int pos = lower_bound(lis, lis + len, a[i]) - lis;
		
		lis[pos] = a[i];
		
		if (pos == len) len++;
	}
	
	cout << len << "\n";
	
	
	return 0;
}
