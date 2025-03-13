#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true)
	{
		cin >> n;
		if (n == -1)
			break;
		
		int t = 1, sum = 0;
		vector<int> v;
		while (t < n)
		{
			if (n % t == 0)
			{
				v.push_back(t);
				sum += t;
			}
				
			t++;
		}
		
		if (sum == n)
		{
			string s = to_string(n) + " = ";
			for (int i = 0; i < v.size(); i++)
			{
				s += to_string(v[i]);
				
				if (i < v.size() - 1)
				{
					s += " + ";
				}
			}
			
			cout << s << "\n";
		}
		else
		{
			cout << n << " is NOT perfect.\n";
		}
	}
	
	return 0;
}
