#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/2636

int n, m, a[104][104], cnt, areaCnt;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool visited[104][104];

void dfs(int y, int x)
{
	visited[y][x] = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (a[ny][nx] == 0)
		{
			dfs(ny, nx);
		}
		else if (a[y][x] == 0 && a[ny][nx] == 1)
		{
			a[ny][nx] += 1;
		}
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
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	
	bool has1 = true;
	while(has1)
	{
		fill(&visited[0][0], &visited[0][0] + n*m, 0);
		
		dfs(0, 0);
		
		has1 = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{	
				if (a[i][j] == 1 && !has1)
				{
					has1 = true;
					break;
				}
			}
		}
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] >= 2 && has1)
				{
					a[i][j] = 0;
				}
			}
		}
		
		cnt++;
		
		/*
		// debug
		cout << "---RESULT " << cnt << "---\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		
		cout << "\ncnt: " << cnt << "\n";
		*/
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] > 0)
				areaCnt++;
		}
	}
	cout << cnt << "\n" << areaCnt << "\n";
	
	
	return 0;
}
