#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/14502

int n, m, a[10][10], c[10][10], cnt, maxCnt;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool visited[10][10];

void dfs(int y, int x)
{
	visited[y][x] = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx] == 0 && c[ny][nx] == 0)
		{
			c[ny][nx] = 2;
			dfs(ny, nx);
		}
	}
}

void buildWalls(int count)
{
	if (count >= 3)
	{
		// 초기화
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				visited[i][j] = false;
				c[i][j] = a[i][j];
			}
		}
		
		// DFS
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (visited[i][j] == 0 && c[i][j] == 2)
				{
					dfs(i, j);
				}
			}
		}
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (c[i][j] == 0)
				{
					cnt++;
				}
			}
		}
		
		
		if (maxCnt < cnt)
			maxCnt = cnt;
		
		return;
	}
	
	// 모든 셀을 순회하며 빈 칸(0)인 곳에 벽(1)을 세움
    for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < m; j++)
		{
            if (a[i][j] == 0)
			{
                a[i][j] = 1;         // 벽 세우기
                buildWalls(count + 1); // 재귀 호출로 다음 벽 세우기
                a[i][j] = 0;         // 백트래킹: 벽 제거
            }
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
	
	buildWalls(0);
	
	cout << maxCnt << "\n";
	
	return 0;
}
