#include<bits/stdc++.h>
using namespace std;

int t, c;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--)
	{
		cin >> c;
		
		for (int i : {25, 10, 5, 1} )
		{
			int cnt = c / i;
			cout << cnt << " ";
			
			c %= i;
		}
		
		cout << "\n";
	}
	
	
	return 0;
}
