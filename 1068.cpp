#include<bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<int> v;

bool isConnected(int idx)
{
	if (v[idx] < 0)
	{
		return v[idx] == -1;
	}
	
	return isConnected(v[idx]);
}

bool isLeaf(int idx)
{	
	for (int i = 0; i < n; i++)
	{
		if (v[i] == idx)
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		
		v.push_back(t);
	}
	cin >> m;
	
	v[m] = -2;
	
	for (int i = 0; i < n; i++)
	{
		if (isLeaf(i) && isConnected(i))
			cnt++;
	}
	
	cout << cnt << "\n";
	
	return 0;
}
