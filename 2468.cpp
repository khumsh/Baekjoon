#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/2468

int n, h, max_h, ret, max_ret, a[104][104];
bool visited[104][104];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int sy, int sx)
{
	visited[sy][sx] = true;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = sy + dy[i];
		int nx = sx + dx[i];
		
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (a[ny][nx] > h && visited[ny][nx] == false)
		{
			dfs(ny, nx);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			
			if (a[i][j] > max_h)
			{
				max_h = a[i][j];
			}
		}
	}
	
	// 비가 오지 않을 경우도 생각해서 0부터 계산 
	for (int t = 0; t <= max_h; t++)
	{
		// reset
		h = t;
		ret = 0;
		fill(&visited[0][0], &visited[0][0] + 104*104, false);
		
		// dfs
		for (int p = 0; p < n; p++)
		{
			for (int q = 0; q < n; q++)
			{
				if (a[p][q] > h && visited[p][q] == false)
				{
					ret++;
					dfs(p, q);
				}
			}
		}
		
		if (ret > max_ret)
		{
			max_ret = ret;
		}
		
		
		/*
		// debug
		cout << "h : " << h << ", ret : " << ret << ", max_ret : " << max_ret << '\n';
		for (int p = 0; p < n; p++)
		{
			for (int q = 0; q < n; q++)
			{
				cout << visited[p][q] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
		*/
	
	}
	
	cout << max_ret << '\n';
	
	return 0;
}
