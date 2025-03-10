#include<bits/stdc++.h>
using namespace std;

int t, n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		
		sort(a.begin(), a.end());
		
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int k;
			cin >> k;
			 
			int l = 0, r = a.size()-1, mid;
			while(l <= r)
			{
				mid = (l + r) / 2;
				
				if (a[mid] == k)
				{
					break;
				}
				else if (a[mid] > k)
				{
					r = mid - 1;
				}
				else
				{
					l = mid + 1;
				}
			}
			
			if (a[mid] == k)
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
			
		}
	}
	
	return 0;
}
