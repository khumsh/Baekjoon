#include<bits/stdc++.h>
using namespace std;

int n, a[1004], lis[1004], lisIdx[1004], prevList[1004], len;

const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	fill(lis, lis + 1004, INF);
	fill(prevList, prevList + 1004, -1);
	
	for (int i = 0; i < n; i++)
	{
		int pos = lower_bound(lis, lis + len, a[i]) - lis;
		
		lis[pos] = a[i];
		lisIdx[pos] = i;
		
		if (pos == len) len++;
		if (pos > 0)
		{
			prevList[i] = lisIdx[pos - 1];
		}
	}
	
	int idx = lisIdx[len - 1];
	vector<int> v;
	for (int i = idx; i != -1; i = prevList[i])
	{
		v.push_back(a[i]);
	}
	
	reverse(v.begin(), v.end());
	
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	
	return 0;
}
