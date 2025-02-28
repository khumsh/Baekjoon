#include<bits/stdc++.h>
using namespace std;

int n, m, a[54][54], visited[54][54], mx;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int y, int x)
{
	fill(&visited[0][0], &visited[0][0] + 54*54, 0);
	visited[y][x] = 1;
	
	queue<pair<int,int>> q;
	q.push({y, x});
	
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
			if (a[ny][nx] == 0) continue;
			
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
			mx = max(mx, visited[ny][nx]);
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
			char c;
			cin >> c;
			if (c == 'L')
			{
				a[i][j] = 1;
			}			
			else if (c == 'W')
			{
				a[i][j] = 0;
			}
				
		}
	}
	
	//
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 1)
				bfs(i, j);
		}
	}
	
	cout << mx - 1 << "\n";
	
	return 0;
}
