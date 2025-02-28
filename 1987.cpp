#include<bits/stdc++.h>
using namespace std;

int n, m, mx, visited[30];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

char a[24][24];

void dfs(int y, int x, int cnt)
{
	mx = max(mx, cnt);
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		int idx = a[ny][nx] - 'A';
		if (!visited[idx])
		{
			visited[idx] = 1;
			dfs(ny, nx, cnt+1);
			visited[idx] = 0;
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
		string s;
		cin >> s;
		
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j];
		}
	}
	
	//
	visited[a[0][0] - 'A'] = 1;
	
	dfs(0, 0, 1);
	
	cout << mx << "\n";
	
	return 0;
}
