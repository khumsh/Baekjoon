#include<bits/stdc++.h>
using namespace std;

int n, m, k, ret, visited[10][10];
char a[10][10];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void debugPrint()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

void go(int y, int x, int cnt)
{
	if (y == 0 && x == m-1 && cnt == k)
	{
		ret++;		
		
		//debugPrint();
		
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (a[ny][nx] == 'T') continue;
		
		visited[ny][nx] = visited[y][x] + 1;
		go(ny, nx, cnt+1);
		visited[ny][nx] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			
			if (a[i][j] == 'T')
				visited[i][j] = 1;
		}
	}
	
	//
	visited[n-1][0] = 1;
	
	go(n-1, 0, 1);
	
	cout << ret << "\n";
	
	return 0;
}
