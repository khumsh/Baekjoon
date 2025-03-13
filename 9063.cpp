#include<bits/stdc++.h>
using namespace std;

int n, mnX = 1e9, mnY = 1e9, mxX = -1e9, mxY = -1e9, a, b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		
		mxX = max(mxX, a);
		mxY = max(mxY, b);
		
		mnX = min(mnX, a);
		mnY = min(mnY, b);
	}
	
	if (n < 2)
	{
		cout << 0 << "\n";
		return 0;
	}
	
	int x = abs(mxX - mnX);
	int y = abs(mxY - mnY);
	
	cout << x * y << "\n";
	
	return 0;
}
