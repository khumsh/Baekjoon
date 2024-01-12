#include<bits/stdc++.h>
using namespace std;

int n, x, res, a[2000004];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		a[t]++;
	}
	
	cin >> x;
	
	for (int i = 0; i < 1000004; i++)
	{
		int j = x - i;
		if (j > i && a[i] > 0 && a[j] > 0) res++;
			
	}
	
	cout << res;
	
	return 0;
}
