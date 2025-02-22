#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/1325

int n, m;

vector<int> v[10004], c;

bool visited[10004];

int go(int here)
{
	visited[here] = true;
	int ret = 1;
	
	for (int it : v[here])
	{		
		if (!visited[it])
			ret += go(it);
	}
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int p, q;
		cin >> p >> q;
		v[q].push_back(p); // p trust q
	}
	
	for (int i = 1; i < n+1; i++)
	{
		fill(&visited[0], &visited[0] + n+1, false);
		int t = go(i);
		c.push_back(t);
	}
	
	int maxCnt = *max_element(&c[0], &c[0] + n);
	for (int i = 0; i < n; i++)
	{
		if (c[i] == maxCnt)
			cout << i+1 << " ";
	}
	
	
	return 0;
}

