#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a[10], avg = 0;
	
	for(int i = 0; i < 5; i++)
	{
		cin >> a[i];
		avg += a[i];
	}
	
	sort(a, a+5);
	avg /= 5;
	
	cout << avg << "\n" << a[2];
	
	
	return 0;
}
