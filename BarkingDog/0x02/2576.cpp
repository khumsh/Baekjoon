#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t, minN = -1, res = 0;
	
	for(int i = 0; i < 7; i++)
	{
		cin >> t;
		
		if (t % 2 != 0)
		{
			res += t;
			
			if (minN < 0 || minN > t) minN = t;
		}
			
	}
	
	if (res == 0) cout << -1;
	else cout << res << "\n" << minN;
	
	return 0;
}
