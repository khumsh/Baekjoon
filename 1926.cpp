#include<bits/stdc++.h>
using namespace std;

int n, m, a[504][504], visited[504][504], cnt, mx;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int bfs(int y, int x)
{
	visited[y][x] = 1;
	
	int ret = 0;
	
	queue<pair<int,int>> q;
	q.push({y, x});
	
	while(q.size())
	{
		ret++;
		
		tie(y, x) = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (a[ny][nx] == 0) continue;
			
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
		}
	}
	
	return ret;
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
	
	// 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j]) continue;
			if (a[i][j] == 0) continue;
			
			int area = bfs(i, j);
			
			cnt++;
			
			mx = max(mx, area);
		}
	}
	
	
	cout << cnt << "\n";
	cout << mx << "\n";
	
	return 0;
}
