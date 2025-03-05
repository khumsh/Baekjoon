#include<bits/stdc++.h>
using namespace std;

int t, n, m, a[20004];
vector<int> b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> t;
	while(t--)
	{
		b.clear();
		
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
		{
			int tempB;
			cin >> tempB;
			b.push_back(tempB);
		}
			
			
		sort(b.begin(), b.end());
		
		int cnt = 0;
		
		for (int i = 0; i < n; i++)
		{
			int l = 0, r = m-1, mid, mx = 0;
			while(l <= r)
			{
				mid = (l + r) / 2;
				if (a[i] > b[mid])
				{
					l = mid + 1;
					mx = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}
			
			//cout << "t: " << t << ", i: " << i << ", mx: " << mx << "\n";
			cnt += mx;
		}
		
		
		cout << cnt << "\n";
	}
	
	
	return 0;
}
