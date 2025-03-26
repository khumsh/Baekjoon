#include<bits/stdc++.h>
using namespace std;

int n, a[24][24], mn = 1e9;

int getSum(vector<int> v)
{
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			sum += a[v[i]][v[j]] + a[v[j]][v[i]];
		}
	}
	
	return sum;
}

void dfs(int idx, vector<int>& v1, vector<int>& v2)
{
	if (idx == n && v1.size() == n/2 && v2.size() == n/2)
	{
		int sum1 = getSum(v1);
		int sum2 = getSum(v2);
		
		mn = min(mn, abs(sum1 - sum2));
		
		return;
	}
	
	if (v1.size() < n/2)
	{
		v1.push_back(idx);
		dfs(idx+1, v1, v2);
		v1.pop_back();
	}
	
	if (v2.size() < n/2)
	{
		v2.push_back(idx);
		dfs(idx+1, v1, v2);
		v2.pop_back();
	}
	
	return;	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	
	vector<int> v1;
	vector<int> v2;
	dfs(0, v1, v2);
	
	cout << mn << "\n";
	
	return 0;
}
