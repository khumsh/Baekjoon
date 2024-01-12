#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a[25];
	
	for (int i = 1; i < 21; i++) a[i] = i;
	
	for (int j = 0; j < 10; j++)
	{
		int m, n;
		cin >> m >> n;
		
		reverse(a+m, a+n+1);
	}
	
	for (int k = 1; k < 21; k++) cout << a[k] << " ";
	
	return 0;
}
