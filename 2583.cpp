#include<bits/stdc++.h>
using namespace std;

// https://www.acmicpc.net/problem/2583

int n, m, k, a[101][101], rec[101][4], cnt, area;
bool visited[101][101];

vector<int> area_vec;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int sy, int sx)
{	
	visited[sy][sx] = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = sy + dy[i];
		int nx = sx + dx[i];
		
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (a[ny][nx] == 0 && visited[ny][nx] == 0)
		{
			area++;
			dfs(ny, nx);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> rec[i][j];
		}
		
		// 사각형 영역 색칠 
		// 2 이상이면 겹친 구역 
		for (int p = rec[i][0]; p < rec[i][2]; p++)
		{
			for (int q = rec[i][1]; q < rec[i][3]; q++)
			{
				a[q][p]++;
			}
		}
	} 
	
	// dfs
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0 && visited[i][j] == 0)
			{
				area = 1;
				cnt++;
				dfs(i, j);
				area_vec.push_back(area);
			}
		}
	}
	
	sort(area_vec.begin(), area_vec.end());
	
	cout << cnt << '\n';
	for (auto v : area_vec)
	{
		cout << v << ' ';
	}
	
	
	
	/*
	// debug
	cout << "cnt : " << cnt << '\n';
	cout << "a:" << '\n';
	for (int p = 0; p < n; p++)
	{
		for (int q = 0; q < m; q++)
		{
			cout << a[p][q] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	cout << "visited:" << '\n';
	for (int p = 0; p < n; p++)
	{
		for (int q = 0; q < m; q++)
		{
			cout << visited[p][q] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	*/
	
	return 0;
}
