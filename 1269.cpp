#include<bits/stdc++.h>
using namespace std;

int n, m;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	
	
	//
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int l = 0, r = m-1, mid;
		while(l <= r)
		{
			mid = (l + r) / 2;
			
			if (a[i] == b[mid])
			{
				break;
			}
			else if (a[i] > b[mid])
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		
		if (a[i] != b[mid])
		{
			cnt++;
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		int l = 0, r = n-1, mid;
		while(l <= r)
		{
			mid = (l + r) / 2;
			
			if (b[i] == a[mid])
			{
				break;
			}
			else if (b[i] > a[mid])
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		
		if (b[i] != a[mid])
		{
			cnt++;
		}
	}
	
	cout << cnt << "\n";
	
	
	return 0;
}
