#include<bits/stdc++.h>
using namespace std;

string ret;
int a, b, c;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true)
	{
		cin >> a >> b >> c;
	
		if (a == 0 && b == 0 && c == 0)
			break;
			
		int mx = max(max(a, b), c);
		
		if (mx == a && a > b + c
			|| mx == b && b > a + c
			|| mx == c && c >= b + a)
		{
			ret = "Invalid";
		}
		else if (a == b && b == c)
		{
			ret = "Equilateral";
		}
		else if (a == b || b == c || c == a)
		{
			ret = "Isosceles";
		}
		else
		{
			ret = "Scalene";
		}
				
		
		cout << ret << "\n";
	}
	
	
	return 0;
}
