#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/15686

int n, m, a[54][54], ret = -1;
vector<pair<int,int>> chickenVec, homeVec;
vector<vector<int>> chickenIdxVec;

int getChickenDist(vector<int> selected)
{
	int sumDist = 0;
	for (auto h : homeVec)
	{
		int mnDist = -1;
		for (auto cIdx : selected)
		{
			int hy, hx, cy, cx;
			tie(hy, hx) = h;
			tie(cy, cx) = chickenVec[cIdx];
			int dist = abs(cy - hy) + abs(cx - hx);
			
			if (mnDist < 0)
				mnDist = dist;
			else
				mnDist = min(mnDist, dist);
		}
		sumDist += mnDist;
	}
	
	return sumDist;
}

void go(int idx, vector<int> v)
{
	if (v.size() >= m)
	{
		int d = getChickenDist(v);
		
		if (ret <= 0)
			ret = d;
		else
			ret = min(ret, d);
		return;
	}
	
	for (int i = idx + 1; i < chickenVec.size(); i++)
	{
		v.push_back(i);
		go(i, v);
		v.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			
			if (a[i][j] == 1)
			{
				homeVec.push_back({i, j});
			}
			else if (a[i][j] == 2)
			{
				chickenVec.push_back({i, j});
			}
		}
	}
	
	vector<int> v;
	go(-1, v);
	
	cout << ret << "\n";
	
	return 0;
}
