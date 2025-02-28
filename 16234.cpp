#include<bits/stdc++.h>
using namespace std;

int n, l, r, a[104][104], visited[104][104];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, vector<pair<int,int>>& unionCells, int& unionCnt)
{
	visited[y][x] = 1;
	
	unionCells.push_back({y, x});
	unionCnt += a[y][x];
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx]) continue;
		if (abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r)
		{
			dfs(ny, nx, unionCells, unionCnt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	
	
	//
	int ans = 0;
	while(ans <= 2000) // 최대 2000번 
	{
		int moveCnt = 0;
		fill(&visited[0][0], &visited[0][0] + 104*104, 0);
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j]) continue;
				
				vector<pair<int,int>> unionCells;
				int unionCnt = 0;
				dfs(i, j, unionCells, unionCnt);
				
				if (unionCells.size() >= 2)
				{
					int average = unionCnt / unionCells.size();
				
					for (auto u : unionCells)
					{
						a[u.first][u.second] = average;
					}
					
					moveCnt++; // 인구이동카운트++ 
				}
			}
		}
		
		
		if (moveCnt == 0) // 인구이동이 없으면 break 
			break;
			
		ans++;
	}
	
	cout << ans << "\n";
	
	
	return 0;
}
