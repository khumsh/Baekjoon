#include<bits/stdc++.h>
using namespace std;

int n, m, h, visited[32][32], ret = 1e9;

bool check()
{
	for (int i = 1; i <= n; i++) // �� ���μ����� 
	{
		int start = i;
		for (int j = 1; j <= h; j++)
		{
			if (visited[j][start]) // ������ ��ٸ��� ������ 
				start++; // ���������� �̵� 
			else if (visited[j][start-1]) // ���� ��ٸ��� ������ 
				start--; // �������� �̵� 
		}
		if (start != i) // ���� ������ ���� ������ ���� ������ false 
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
			// ��ٸ��� ������ �ѱ�� 
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
		visited[a][b] = 1; // ��ٸ� ����
	}
	
	//
	go(1, 0);
	
	if (ret == 1e9)
		cout << -1 << "\n";
	else
		cout << ret << "\n";
	
	
	return 0;
}
