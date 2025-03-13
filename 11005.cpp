#include<bits/stdc++.h>
using namespace std;

string ret;
int a, b, n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> b;
	while (n > 0)
	{
		int r = n % b;
		
		char c;
		if (r >= 0 && r <= 9)
		{
			c = r + '0';
		}
		else
		{
			c = r - 10 + 'A';
		}
		ret.push_back(c);
		
		n /= b;
	}
	
	reverse(ret.begin(), ret.end());
	
	cout << ret << "\n";
	
	return 0;
}
