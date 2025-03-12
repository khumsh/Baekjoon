#include<bits/stdc++.h>
using namespace std;

int a[6];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n[6] = {1, 1, 2, 2, 2, 8};
	
	for (int i = 0; i < 6; i++)
	{
		cin >> a[i];
		
		cout << n[i] - a[i] << " ";
	}
	
	return 0;
}
