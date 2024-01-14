#include<bits/stdc++.h>
using namespace std;

int pre[5004], nxt[5004], res[5004];
int n, k, len = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	for (int i = 1; i < n+1; i++)
	{
		pre[i] = (i == 1) ? n : i-1;
		nxt[i] = (i == n) ? 1 : i+1;
		len++;
	}
	
	int i = 1, cur = 1;
	while (len > 0)
	{
		if (i == k)
		{ 
			pre[nxt[cur]] = pre[cur];
			nxt[pre[cur]] = nxt[cur];
			res[n - len] = cur;
			i = 0;
			len--;
		}
		else
		{
			cur = nxt[cur];
			i++;
		}
	}
	
	cout << "<";
	for (int j = 0; j < n; j++)
	{
		if (j == n - 1) cout << res[j];
		else cout << res[j] << ", ";
	}
	cout << ">";
	
	return 0;
}
