#include<bits/stdc++.h>
using namespace std;

int n, x, ret, a[100004];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> x;
	
	sort(a, a + n);
	
	int l = 0, r = n - 1;
	while(l < r)
	{
		int sum = a[l] + a[r];
		if (sum >= x)
		{
			if (sum == x)
				ret++;
			
			r--;
		}
		else
		{
			l++;
		}
	}
	
	cout << ret << "\n";
	
	
	return 0;
} 
