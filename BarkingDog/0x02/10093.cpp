#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long a, b;
	cin >> a >> b;
	
	if (a == b)
	{
		cout << 0;
		return 0;
	}
	else if (a > b)
	{
		long long temp = a;
		a = b;
		b = temp;
	}
	
	cout << b - a - 1 << "\n";
	for (long long i = a + 1; i < b; i++)
	{
		cout << i << " ";
	}
	
	return 0;
}
