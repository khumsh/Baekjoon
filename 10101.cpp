#include<bits/stdc++.h>
using namespace std;

int a, b, c;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c;
	
	string ret;
	
	if (a + b + c != 180)
	{
		ret = "Error";
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
	
	return 0;
}
