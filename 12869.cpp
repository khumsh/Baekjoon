#include<bits/stdc++.h>
using namespace std;

int n, a[3], visited[64][64][64];

int dmg[6][3] = 
{
	{ 9, 3, 1 },
	{ 9, 1, 3 },
	{ 3, 9, 1 },
	{ 3, 1, 9 },
	{ 1, 3, 9 },
	{ 1, 9, 3 },
};

struct HP
{
	int a, b, c;
};

int bfs(int a, int b, int c)
{
	visited[a][b][c] = 1;
	
	queue<HP> q;
	q.push({a, b, c});
	
	while(q.size())
	{
		auto t = q.front();
		int a = t.a;
		int b = t.b;
		int c = t.c;
		q.pop();
		
		if (visited[0][0][0])
		{
			return visited[0][0][0] - 1;
		}
		
		for (int i = 0; i < 6; i++)
		{
			int na = max(0, a - dmg[i][0]);
			int nb = max(0, b - dmg[i][1]);
			int nc = max(0, c - dmg[i][2]);
			
			if (visited[na][nb][nc]) continue;
			
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({na, nb, nc});
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	//
	int cnt = bfs(a[0], a[1], a[2]);
	
	cout << cnt << "\n";
	
	return 0;
}
