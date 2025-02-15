#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, pos = -1, len = 0, plus_cnt = 0;
	cin >> n;
	
	vector<char> res;
	int a[n] = {}, ans[n];
	
	for (int i = 0; i < n; i++) a[i] = i+1;
		
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		ans[i] = t;
	}
	
	while(len < n)
	{
		if (len == 0)
		{
			for (int i = 0; i < ans[len]; i++)
			{
				pos++;
				res.push_back('+');
				plus_cnt++;
			}
			if (ans[len] == a[pos])
			{
				a[pos] = -1;
				pos--;
				len++;
				res.push_back('-');
			}
		}
		else
		{
			if (ans[len] == a[pos])
			{
				a[pos] = -1;
				pos--;
				len++;
				res.push_back('-');
			}
			else if (ans[len] < pos+1)
			{
				if (a[pos] != -1 && plus_cnt == n)
				{
					cout << "NO";
					return 0;
				}
				
				do
				{
					pos--;
				}
				while (ans[len] < pos+1);
				
				if (ans[len] == a[pos])
				{
					a[pos] = -1;
					pos--;
					len++;
					res.push_back('-');
				}
				else
				{
					cout << "NO";
					return 0;
				}
			}
			else if (ans[len] > pos+1)
			{
				do
				{
					pos++;
					
					if (a[pos] != -1) 
					{
						res.push_back('+');
						plus_cnt++;
					}
				}
				while (ans[len] > pos+1);
				
				if (ans[len] == a[pos])
				{
					a[pos] = -1;
					pos--;
					len++;
					res.push_back('-');
				}
				else
				{
					cout << "NO";
					return 0;
				}
			}
		}
		
		
	}

	for(int i = 0; i < res.size(); i++)
	{
		if (i != res.size() - 1) cout << res[i] << "\n";
		else cout << res[i];
	}
		
	
	return 0;
}
