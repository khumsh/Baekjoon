#include<bits/stdc++.h>
using namespace std;

int n;
double a[10004], ret = -1e9;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		double res = a[i];
		ret = max(ret, res);
		for (int j = i + 1; j < n; j++)
		{
			res *= a[j];
			ret = max(ret, res);
		}
	}
	
	cout << fixed << setprecision(3) << ret << "\n";
	
	return 0;
}
