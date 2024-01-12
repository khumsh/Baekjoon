#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a[25], resM = 0, resY = 0;
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for(int j = 0; j < n; j++)
	{
		resY += (a[j] / 30 + 1) * 10;
		resM += (a[j] / 60 + 1) * 15;
	}
	
	if (resM == resY) cout << "Y M " << resM;
	else if (resM < resY) cout << "M " << resM;
	else cout << "Y " << resY;
	
	return 0;
}
