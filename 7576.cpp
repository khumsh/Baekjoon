#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/7576

int n, m, y, x, ret, a[1004][1004], visited[1004][1004];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	queue<pair<int,int>> q;
	
	// input
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			
			if (a[i][j] == 1)
			{
				q.push({i, j});
				visited[i][j] = 1;
			}
				
		}
	}
	
	while(q.size())
	{
		tie(y, x) = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (a[ny][nx] >= 0)
			{
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ny, nx});
				
				ret = max(ret, visited[ny][nx] - 1);
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == 0 && a[i][j] == 0)
			{
				cout << "-1\n";
				return 0;
			}
				
		}
	}
	
	cout << ret << "\n";
	
	
	return 0;
}
