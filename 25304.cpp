#include<bits/stdc++.h>
using namespace std;

int x, n, a, b, sum;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		
		sum += a * b;
	}
	
	string ret = (x == sum) ? "Yes" : "No";
	
	cout << ret << "\n";
	
	return 0;
}
