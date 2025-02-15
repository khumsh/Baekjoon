#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/1012

int t, n, m, k, x, y, ret;

int a[51][51];
bool visited[51][51];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int sy, int sx)
{
	if (visited[sy][sx]) return;
	
	visited[sy][sx] = true;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = sy + dy[i];
		int nx = sx + dx[i];
		
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		
		if (a[ny][nx] == 1 && visited[ny][nx] == false)
		{
			dfs(ny, nx);
		}
		
	}
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	// input
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> k;
		
		// reset
		fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		ret = 0;
		
		for (int j = 0; j < k; j++)
		{
			cin >> x >> y;
			a[y][x] = 1;
		}
		
		// dfs
		for (int p = 0; p < n; p++)
		{
			for (int q = 0; q < m; q++)
			{
				if (a[p][q] == 1 && visited[p][q] == false)
				{
					dfs(p, q);
					ret++;
				}
			}
		}
		
		//cout << "TestCase" << i+1 << ": " << ret << endl;
		cout << ret << endl;
	}
	
	
	return 0;
}
