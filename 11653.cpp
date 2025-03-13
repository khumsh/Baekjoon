#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	int t = 2;
	while (n != 1)
	{
		if (n % t == 0)
		{
			cout << t << "\n";
			n /= t;
		}
		else
		{
			t++;
		}
	}
	
	return 0;
}
