#include<bits/stdc++.h>
using namespace std;

int n, m, h, visited[32][32], ret = 1e9;

bool check()
{
	for (int i = 1; i <= n; i++) // 각 세로선마다 
	{
		int start = i;
		for (int j = 1; j <= h; j++)
		{
			if (visited[j][start]) // 오른쪽 사다리가 있으면 
				start++; // 오른쪽으로 이동 
			else if (visited[j][start-1]) // 왼쪽 사다리가 있으면 
				start--; // 왼쪽으로 이동 
		}
		if (start != i) // 도착 지점이 시작 지점과 같지 않으면 false 
			return false;
	}
	
	return true;
}

void go(int here, int cnt)
{
	if (cnt > 3 || cnt >= ret) return;
	if (check())
	{
		ret = min(ret, cnt);
		return;
	}
	
	for (int i = here; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// 사다리가 있으면 넘기기 
			if (visited[i][j] || visited[i][j-1] || visited[i][j+1]) continue;
			
			visited[i][j] = 1;
			go(i, cnt+1);
			visited[i][j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// input
	cin >> n >> m >> h;
	for (int j = 0; j < m; j++)
	{
		int a, b;
		cin >> a >> b;
		visited[a][b] = 1; // 사다리 놓기
	}
	
	//
	go(1, 0);
	
	if (ret == 1e9)
		cout << -1 << "\n";
	else
		cout << ret << "\n";
	
	
	return 0;
}
